#include "minishell.h"

static int		rc_file_init(t_shell *shell)
{
	char	*home;
	int		fd;

	home = ft_strjoin(shell->env_get(shell, "HOME"), "/.mshrc");
	fd = open(home, O_RDONLY);
	free(home);
	return (fd);
}

static char		rc_command_loop(t_shell *shell, t_command *cmd_lst)
{
	int			i;
	char		exit;

	i = 0;
	exit = 0;
	while (cmd_lst && cmd_lst[i].end != 1)
	{
		if (!exit && ft_str_isequal(cmd_lst[i].command.content, "exit"))
			exit = 1;
		if (!exit)
		{
			if (!check_command(shell, &cmd_lst[i].command))
				shell->exec(shell, cmd_lst, i);
			else
				ft_printf("minishell: %s: No such file or directory\n",
						cmd_lst[i].command.content);
		}
		if (cmd_lst[i].argv)
			clear(cmd_lst[i].argv);
		cmd_lst[i].command.clear(&cmd_lst[i].command);
		i++;
	}
	return (exit);
}

int				rc_parser(t_shell *shell, int fd)
{
	int 		gnl_ret;
	int			exit;
	char		*line;
	t_command	*cmd_lst;

	if (!fd)
		fd = rc_file_init(shell);
	if (fd < 0)
		return (1);
	gnl_ret = get_next_line(fd, &line);
	cmd_lst = parse_command(line);
	if (cmd_lst == NULL || clean_command(shell, cmd_lst) < 0)
	{
		ft_printf("ERROR\n");
		if (gnl_ret == 0)
			return (0);
		return (rc_parser(shell, fd));
	}
	exit = (int)rc_command_loop(shell, cmd_lst);
	free(cmd_lst);
	if (!exit && gnl_ret != 0)
		return (rc_parser(shell, fd));
	close(fd);
	return (0);
}
