//
// Created by Mathieu LABOURIER on 6/29/20.
//

#include "parsing.h"
#include "minishell.h"

int			open_typ(char *file, t_command cmd)
{
	if (cmd.redirect.dest > 2)
		close(cmd.redirect.dest);
	if (cmd.redirect.type == '>')
		return (open(file, O_RDWR | O_TRUNC | O_CREAT, 00644));
	else if (cmd.redirect.type == '>' + '>')
		return (open(file, O_RDWR | O_APPEND | O_CREAT, 00644));
	else if (cmd.redirect.type == '<')
		return (open(file, O_RDONLY));
	return (-1);
}

int			get_src(t_command *cmd, int i, int index)
{
	char	*cur;

	i--;
	cur = cmd->argv[index];
	if (i > 0 && ft_cinset(cur[i], "<>"))
		i--;
	while (i > 0 && ft_isdigit(cur[i]))
		i--;
	cmd->redirect.src = 1;
	if (cmd->redirect.type == '<')
		cmd->redirect.src = 0;
	if (i == 0)
		cmd->redirect.src = ft_atoi(cur);
	return (index);
}

int			get_dest(t_command *cmd, int i, int index)
{
	char	*cur;
	char	*temp;

	cur = cmd->argv[index];
	if (!cur[i])
	{
		if (!cmd->argv[index + 1])
			return (-ERRNLSYMBOL);
		cmd->redirect.dest = open_typ(cmd->argv[index + 1], *cmd);
		return (index + 1);
	}
	else
	{
		temp = ft_substr(cur, i, ft_strlen(cur));
		if (!temp)
			return (-ERRMALLOC);
		cmd->redirect.dest = open_typ(temp, *cmd);
		free(temp);
	}
	return (index);
}