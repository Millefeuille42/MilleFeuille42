/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 17:05:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
#	define MINISHELL_H
#   include "libft.h"
#   include "ft_list.h"
#	include "libft_string.h"
#   include <sys/wait.h>
#   include <errno.h>
#   include <string.h>

/*
**  Structure dans laquelle on pourra placer:
**  - ret: retour des fonctions
**  - cwd (current working directory): le chemin actuel
**  - prompt:  le prompt  du shell
**  - env: une liste chainée contenant les variables d'environnement (système clef/valeur)
*/
typedef struct	s_command
{
	t_string	command;
	char		**argv;
	char		end;
}				t_command;

typedef struct  s_shell
{
    int         ret;
    t_string    prompt;
    t_list      env;
    void        (*add_env)(struct s_shell *, char*, char*);
    void        (*print_env)(struct s_shell *);
    void        (*show_prompt)(struct s_shell *);
    void        (*clear_env)(struct s_shell *);
    void        (*env_remove)(struct s_shell *, char *);
	void        (*replace_env)(struct s_shell *, char *, char *);
    void        (*exec)(struct s_shell *, t_command *, int);
    char*       (*env_get)(struct s_shell *, char* key);
    int         (*run)(struct s_shell *);
}               t_shell;

/*
**                  Méthodes de l'objet t_shell
*/
void        ft_add_env(t_shell *shell, char *key, char *value);     /* Fonction qui ajoute une variable d'environnement */
void        ft_display_env(t_shell *shell);                         /* Fonction qui afficher les variables d'environnement */
void        ft_show_prompt(t_shell *shell);                         /* Fonction qui affiche un prompt */
void        ft_clear_env(t_shell *shell);                           /* Fonction qui clean les variables d'environnement */ 
void        ft_env_remove(t_shell *shell, char *key);               /* Fonction qui supprime une variable d'environnement en fonction de sa clef*/
void		ft_replace_env(t_shell *shell, char *key, char *value);
void        ft_exec(t_shell *shell, t_command *cmd, int index);
int         run(t_shell *shell);                                    /* Fonction qui lance le shell */
char        *ft_env_get(t_shell *shell, char *key);                 /* Fonction qui permet de récupérer une variable d'environnement par sa clef */
t_shell     ft_shell(void);                                         /* Fonction qui initialise le shell */


/*
**              Structure d'une variable d'environnement
*/
typedef struct s_env
{
    char *key;
    char *value;
}               t_env;



int			array_len(char **array);
int			clean_command(t_shell *shell, t_command *commands);
int			check_command(t_shell *shell, t_string *command);
int			rc_parser(t_shell *shell, int fd);
int         ft_test_builtin(t_shell *shell, t_command *cmd_lst);

char		file_exists(const char *filename);

char		**ft_delete_entry(char **array, int index);
char        **ft_extract_env(char *str);
char		**parse_path(t_shell *shell);
char		*swap_var(t_shell *shell, char *str);

size_t      ft_len(char **str);                                     /* Fonction qui calcul la taille d'un char** */

t_command	*parse_command(char *line);

t_string	ft_getcwd(void);                                        /* Fonction qui retourne le chemin courant*/

/* 
**   BUILTIN FUNCTION 
*/

int         ft_cd(t_shell *shell, char *argv[]);                    /*  Comme la vraie fonction cd      */
int         ft_echo(char *argv[]);                                  /*  Comme la vraie fonction echo    */
int         ft_pwd(void);                                           /*  Comme la vraie fonction pwd     */
int         ft_export(t_shell *shell, char *argv[]);                /*  Comme la vraie fonction export  */
int         ft_unset(t_shell *shell, char *argv[]);                 /*  Comme la vraie fonction unset   */
int         ft_env(t_shell *shell, char *argv[]);                   /*  Comme la vraie fonction env     */
#	endif
