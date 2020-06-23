#ifndef PARSING_H
# define PARSING_H

# define ERRMALLOC		3
# define ERRSYMBOL		1
# define ERRDBSYMBOL	2
# define ERRCTRLD		4
# define ERREMPTY		5

char	is_escape(const char *str, int i);
int		skip_wp(char *input, int i);
int		skip_quote(const char *input, int i, char quote);

int		get_next_arg(char *input, int *s, char **str);
int		get_next_command(char *input, int *s, char **str);
int		get_n(char *input, int(*g)(char *, int *, char **), char ***ret);
int		get_input(t_shell *shell, char **input);

#endif
