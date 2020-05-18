/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:00:04 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 20:00:04 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include "graphical.h"

typedef	struct	s_bmp_info
{
	int			width;
	int			height;
	int			size;
	short int	bpp;
}				t_bmp_info;

#endif
