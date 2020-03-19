/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.h                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:48:45 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/19 11:11:50 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

# define UP		65362
# define LEFT	65361
# define DOWN	65364
# define RIGHT	65363
# define ESCAPE	65307


typedef struct		s_key
{
	char			keyc[65363];
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

int				raycasting(t_win cub);
t_ray 			ray_fst_quarter(t_ray r, double r_a);
t_ray 			ray_scd_quarter(t_ray r, double r_a);
t_ray 			ray_trd_quarter(t_ray r, double r_a);
t_ray 			ray_frt_quarter(t_ray r, double r_a);
t_win			draw(t_win cub, t_ray r, int x);

t_win			keys_init(t_win cub);
int				key_rhook(int key, t_win *cub);
int				keyp_hook(int key, t_win *cub);

void 			up(t_win **cub);
void 			down(t_win **cub);
void 			left(t_win **cub);
void 			right(t_win **cub);
void 			escape(t_win **cub);

t_img create_image(t_win cub);

# endif
