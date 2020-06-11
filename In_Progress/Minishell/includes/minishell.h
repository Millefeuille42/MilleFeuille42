/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/11 16:32:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
#	define MINISHELL_H
#   include "libft.h"
#   include "ft_list.h"
#	include "libft_string.h"


/*
**  Structure dans laquelle on pourra placer:
**  - ret: retour des fonctions
**  - cwd (current working directory): le chemin actuel
**  - env: une liste chainée contenant les variables d'env (nécessite quelques méthodes afin de faciliter l'ajout/suppression des variables)
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
    int         (*run)(struct s_shell *);
}               t_shell;

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
void        ft_add_env(t_shell *shell, char *key, char *value);     /* Fonction qui ajoute une variable d'environnement */
void        ft_display_env(t_shell *shell);                         /* Fonction qui afficher les variables d'environnement */
void        ft_show_prompt(t_shell *shell);
int         run(t_shell *shell);
int			array_len(char **array);
t_shell     ft_shell(void);                                         /* Fonction qui initialise le shell */
t_command	*parse_command(char *line);

#	endif
