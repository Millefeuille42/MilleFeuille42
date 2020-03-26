/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.h                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:48:45 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/26 18:02:37 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

# define UP			119
# define LEFT		97
# define DOWN		115
# define RIGHT		100
# define R_UP		65362
# define R_LEFT		65361
# define R_DOWN		65364
# define R_RIGHT	65363
# define ESCAPE		65307

typedef struct		s_key
{
	char			keyc[66000];
	char			keyl[7];
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
	int				inc_u;
	int				inc_d;
}					t_win;

typedef struct		s_draw
{
	int				s;
	int				e;
	double			dist;
}					t_draw;

int				raycasting(t_win cub);

t_ray 			ray_fst_quarter(t_ray r, t_conf conf);
t_ray 			ray_scd_quarter(t_ray r, t_conf conf);
t_ray 			ray_trd_quarter(t_ray r, t_conf conf);
t_ray 			ray_frt_quarter(t_ray r, t_conf conf);

t_win			draw(t_win cub, t_ray r, int x, double r_a);
void			minimap(t_win cub);
t_img			create_image(t_win cub);
t_img			image_pixel_put(int x, int y, t_img img, t_plan color);

t_win			keys_init(t_win cub);
int				key_rhook(int key, t_win *cub);
int				keyp_hook(int key, t_win *cub);

void 			up(t_win **cub);
void 			down(t_win **cub);
void 			left(t_win **cub);
void 			right(t_win **cub);
void 			r_up(t_win **cub);
void 			r_down(t_win **cub);
void 			r_left(t_win **cub);
void 			r_right(t_win **cub);
void 			escape(t_win **cub);

# endif
