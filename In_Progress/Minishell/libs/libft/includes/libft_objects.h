/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_objects.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:53:50 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:40:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_OBJECTS_H
#	define LIBFT_OBJECTS_H

typedef struct		s_format
{
	char			converter;
	int				min;
	int				max;
	int				point;
	int				padding;
	int				inversed;
	int				min_zero;
	int				max_zero;
	int				space_padding;
	int				zero_padding;
	char			*flag;
}					t_format;

#	endif
