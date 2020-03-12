/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:48:45 by mlabouri          #+#    #+#             */
//*   Updated: 2020/03/12 19:33:17 by mlabouri         ###   ########          */
*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

# define UP		126
# define LEFT	124
# define DOWN	125
# define RIGHT	123
# define ESCAPE	53


typedef struct		s_key
{
	char			keyc[255];
	int				length;
	char			keyl[5];
}					t_key;

typedef struct		s_img
{
	void			*v_img;
	char			*c_img;
	int 			bpp;
	int 			sl;
	int 			endian;
}					t_img;

typedef struct 		s_ray
{
	t_dbl_co		dir;
	t_dbl_co		coef;
	t_dbl_co		cpos;
	t_dbl_co		opos;
	t_int_co		mpos;
}					t_ray;

typedef struct 		s_win
{
	t_conf			*conf;
	void 			*mlx;
	void 			*win;
	t_img			img;
	t_key 			keys;
}					t_win;

typedef struct		s_draw
{
	int				s;
	int				e;
	double			dist;
}					t_draw;

int				graphics(t_conf *conf);

int				raycasting(t_win cub);
t_ray 			ray_fst_quarter(t_ray r);
t_ray 			ray_scd_quarter(t_ray r);
t_ray 			ray_trd_quarter(t_ray r);
t_ray 			ray_frt_quarter(t_ray r);
t_win			draw(t_win cub, t_ray r, int x);

t_win			keys_init(t_win cub);
int				key_rhook(int key, t_win *cub);
int				keyp_hook(int key, t_win *cub);

void 			up(t_win **cub);
void 			down(t_win **cub);
void 			left(t_win **cub);
void 			right(t_win **cub);
void 			escape(t_win **cub);

# endif
