/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:00:45 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 11:56:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_list.h"
# include "libft_string.h"
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <signal.h>
# include <sys/stat.h>
# include "sort_arg.h"

# define SEPARATOR "<>;|"
# define SYNTAX_ERROR "minishell: erreur de syntaxe prés du symbole inattendu"

typedef	struct		s_redirect
{
	t_string		dest;
	char			type;
}					t_redirect;

typedef	struct		s_command
{
	char			*command;
	t_string		argv;
	int				pipe[2];
	int				end;
	int				actual_fd;
	int				stdin;
	int				stdout;
	int				stdout_saved;
	int				stdin_saved;
	t_redirect		redirect;
}					t_command;

typedef	struct		s_shell
{
	int				ret;
	t_string		prompt;
	t_list			env;
	t_list			lst_cmd;
	int				loop;
	pid_t			pid;
	int				process_status;
	char			*input;
	int				exit;
	unsigned char	exit_code;
	void			(*add_env)(struct s_shell *, char*, char*);
	void			(*print_env)(struct s_shell *);
	void			(*show_prompt)(struct s_shell *);
	void			(*clear_env)(struct s_shell *);
	void			(*env_remove)(struct s_shell *, char *);
	void			(*replace_env)(struct s_shell *, char *, char *);
	void			(*exec)(struct s_shell *, t_command *, int);
	void			(*clean)(struct s_shell *);
	char			*(*env_get)(struct s_shell *, char* key);
	int				(*run)(struct s_shell *);
}					t_shell;

typedef	struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

void				ft_add_env(t_shell *shell, char *key, char *value);
void				ft_display_env(t_shell *shell);
void				ft_show_prompt(t_shell *shell);
void				ft_clear_env(t_shell *shell);
void				ft_env_remove(t_shell *shell, char *key);
void				ft_replace_env(t_shell *shell, char *key, char *value);
void				ft_exec(t_shell *shell, t_command *cmd);
void				ft_clean_shell(t_shell *shell);
int					ft_run(t_shell *shell);
char				*ft_env_get(t_shell *shell, char *key);

t_shell				ft_shell(void);

int					ft_cd(t_shell *shell, char *argv[]);
int					ft_echo(char *argv[]);
int					ft_pwd(t_shell *shell);
int					ft_export(t_shell *shell, char *argv[]);
int					ft_unset(t_shell *shell, char *argv[]);
int					ft_env(t_shell *shell, char *argv[]);
int					ft_exit(t_shell *shell, char **argv);

t_command			*ft_command(void);
char				*ft_get_command(char *str, t_shell *shell, t_command *cmd);
char				*ft_parse_args(t_shell *shell, char *str, t_command *cmd);
char				*ft_handle_stdin_redirect(t_shell *shell, t_command *cmd,\
						char *str);
char				*ft_handle_stdout_redirect(t_shell *shell, t_command *cmd,\
						char *str);
char				*ft_handle_pipe(t_shell *shell, t_command *cmd, char *str);
char				*ft_find_command(char *path, char *cmd);
char				*ft_remove_char(char *input, char c);
char				*ft_replace_input(t_shell *shell, char *input);
char				*ft_safe_extract(t_shell *shell, char *str, char **tmp, int\
						(*f)(char *, int));
char				**ft_sort_arg(char *str);
char				**ft_extract_env(char *str);

int					ft_test_builtin(t_shell *shell, t_command *cmd_lst);
int					ft_is_sep_and_space(int c);
int					ft_isseparator(int c);
int					ft_is_escape(char *str);
int					ft_parse_input(t_shell *shell, char *str);
int					ft_read_input(t_shell *shell);
int					ft_check_input(char *input);
int					ft_iscommand(char *str, int quote);
int					ft_isarg(char *str, int quote);

void				ft_del_cmd(t_element *element);
void				ft_close_fd(t_command *cmd);

size_t				ft_len(char **str);

t_string			ft_getcwd(void);

char				**clean_args(char **args);

void				safe_free(void **element);

char				**ft_ret_env(t_shell *shell);
void				ft_print_error(const char *str, ...);
void				ft_syntax_error(t_shell *shell);
#endif
