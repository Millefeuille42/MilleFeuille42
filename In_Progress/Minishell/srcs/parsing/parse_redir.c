//
// Created by Mathieu LABOURIER on 6/25/20.
//

#include "parsing.h"
#include "minishell.h"

int clean_end(t_command *cmd, int index, int a_end)
{
	char	*str_t;
	int		i;

	if (cmd->redirect.type == '<')
		ft_swap_int(&cmd->redirect.src, &cmd->redirect.dest);
	if (a_end != index)
		cmd->argv = delete_entry(cmd->argv, a_end);
	if (!cmd->argv)
		return (ERRMALLOC);

	i = iter_until_set(cmd->argv[index], "<>");

	if (i == 0 || (i > 0 && !ft_isdigit(cmd->argv[index][i - 1])))
	{
		str_t = ft_substr(cmd->argv[index], 0, i);
		if (!(str_t))
			return (ERRMALLOC);
		if (cmd->argv[index])
			free(cmd->argv[index]);
		cmd->argv[index] = str_t;
	}
	else
		cmd->argv = delete_entry(cmd->argv, index);
	if (!cmd->argv)
		return (ERRMALLOC);

	if (!(str_t = ft_strdup(cmd->argv[0])))
	{
		clear(cmd->argv);
		return (ERRMALLOC);
	}
	free(cmd->command);
	cmd->command = str_t;
	return (-1);
}

int			get_redir(t_command *cmd, int i, int index)
{
	int		a_start;
	int		a_end;
	char	*cur;

	cur = cmd->argv[index];
	cmd->redirect.type = (cur[i] == '>') ? '>' : '<';
	if (cur[i + 1] == '>')
		cmd->redirect.type += '>';
	i++;
	if ((a_start = get_src(cmd, i, index)) < 0)
		return (-a_start);
	if (cur[i] && cur[i] == '>')
		i++;
	if ((a_end = get_dest(cmd, i, index)) < 0)
		return (-a_end);
	return (clean_end(cmd, index, a_end));
}

int			check_part(t_command *cmd, int index)
{
	int		i;
	int		err;
	char	*cur;

	i = 0;
	err = 0;
	cur = cmd->argv[index];
	while (cur[i])
	{
		if ((cur[i] == '>' || cur[i] == '<') && !is_escape(cur, i))
		{
			err = get_redir(cmd, i, index);
			break ;
		}
		i++;
	}
	return (err);
}

int		parse_redir(t_command *command)
{
	int	i;
	int i_com;
	int err;

	i_com = 0;
	while (!command[i_com].end)
	{
		i = 0;
		while (command->argv[i])
		{
			err = check_part(command, i);
			if (err > 0)
				return (err);
			i++;
			if (err < 0)
				i = 0;
		}
		i_com++;
	}
	return (0);
}