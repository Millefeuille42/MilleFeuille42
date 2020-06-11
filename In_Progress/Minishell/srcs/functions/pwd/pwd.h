/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:16:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 17:15:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PWD_H
#   define PWD_H
#   include "libft.h"
#	include "libft_string.h"

t_string	ft_getcwd(void);   /* Fonction qui retourne le chemin courant*/
void		pwd(void);          /* Fonction qui affiche le chemin courant avec un \n <- identique au vrai pwd */

#   endif

