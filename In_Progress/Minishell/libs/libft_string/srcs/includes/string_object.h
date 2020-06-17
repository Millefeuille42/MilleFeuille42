/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_object.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:53:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_OBJECT_H
# define STRING_OBJECT_H

# include "libft_string.h"

typedef struct	s_string
{
	size_t		size;
	char		*content;

	void		(*clear)(struct s_string *);
	void		(*prepend)(struct s_string *, const char *);
	void		(*push)(struct s_string *, char *);
	void		(*upper)(struct s_string *);
	void		(*lower)(struct s_string *);
	void		(*replace)(struct s_string *, const char *, const char *, int);
	void		(*delete)(struct s_string *, const char *, int);
}				t_string;

t_string		ft_string(char *str);
void			ft_clear_string(t_string *string);
void			ft_push_string(t_string *string, char *str);
void			ft_string_up(t_string *string);
void			ft_string_low(t_string *string);
void			ft_prepend(t_string *str, const char *new_str);
void			ft_replace(t_string *str, const char *o, const char *ne, int n);
void			ft_delete(t_string *str, const char *str2, int n);

#endif
