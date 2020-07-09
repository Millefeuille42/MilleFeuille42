#ifndef PARSING_H
# define PARSING_H

# define ERRSYMBOL		1
# define ERRDBSYMBOL	2
# define ERRMALLOC		3
# define ERRCTRLD		4
# define ERREMPTY		5
# define ERRNLSYMBOL	6

#include "minishell.h"

char	is_escape(const char *str, int i);
char	**delete_entry(char **arr, int entry);
int		skip_wp(char *input, int i);
int		skip_quote(const char *input, int i, char quote);
int		iter_until_set(char *str, char *set);

int		get_next_arg(char *input, int *s, char **str);
int		get_next_command(char *input, int *s, char **str);
int		get_n(char *input, int(*g)(char *, int *, char **), char ***ret);

int		get_src(t_command *cmd, int i, int index);
int		get_dest(t_command *cmd, int i, int index);
int		parse_redir(t_command *command);

#endif
