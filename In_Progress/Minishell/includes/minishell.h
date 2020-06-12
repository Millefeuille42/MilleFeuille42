/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/12 12:28:50 by dboyer           ###   ########.fr       */
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
typedef struct  s_shell
{
    int         ret;
    char        *cwd;
    t_string    prompt;
    t_list      env;
    void        (*add_env)(struct s_shell *, char*, char*);
    void        (*print_env)(struct s_shell *);
    void        (*show_prompt)(struct s_shell *);
    void        (*clear_env)(struct s_shell *);
    void        (*env_remove)(struct s_shell *, char *);
    void        (*exec)(struct s_shell *, char **);
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
void        ft_exec(t_shell *shell, char **cmd);
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

typedef struct	s_command
{
	t_string	command;
	char		**argv;
	char		end;
}				t_command;


t_string	ft_getcwd(void);                                        /* Fonction qui retourne le chemin courant*/

void		pwd(void);                                              /* Fonction qui affiche le chemin courant avec un \n <- identique au vrai pwd */

int			array_len(char **array);
char		**ft_delete_entry(char **array, int index);

t_command	*parse_command(char *line);
int			clean_command(t_command *commands);

#	endif
