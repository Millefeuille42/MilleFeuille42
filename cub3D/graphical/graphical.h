/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/13 16:05:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICAL_H
# define GRAPHICAL_H

# include "../cub3d.h"

# if __APPLE__

#  define UP		13
#  define LEFT		0
#  define DOWN		1
#  define RIGHT		2
#  define R_UP		126
#  define R_LEFT	124
#  define R_DOWN	125
#  define R_RIGHT	123
#  define ESCAPE	53

# else

#  define UP		119
#  define LEFT		97
#  define DOWN		115
#  define RIGHT		100
#  define R_UP		65362
#  define R_LEFT	65361
#  define R_DOWN	65364
#  define R_RIGHT	65363
#  define ESCAPE	65307

# endif

typedef struct		s_key
{
	char			keyc[66000];
	char			keyl[7];
}					t_key;

typedef struct		s_ray
{
	t_dbl_co		dir;
	t_dbl_co		coef;
	t_dbl_co		cpos;
	t_dbl_co		opos;
	t_int_co		mpos;
}					t_ray;

typedef struct		s_win
{
	t_conf			*conf;
	void			*mlx;
	void			*win;
	t_img			img;
	t_key			keys;
	int				inc_u;
	int				inc_d;
}					t_win;

typedef struct		s_draw
{
	int				s;
	int				e;
	double			dist;
}					t_draw;

int					raycasting(t_win cub);

t_ray				ray_fst_quarter(t_ray r, t_conf conf);
t_ray				ray_scd_quarter(t_ray r, t_conf conf);
t_ray				ray_trd_quarter(t_ray r, t_conf conf);
t_ray				ray_frt_quarter(t_ray r, t_conf conf);

t_img				create_image(t_win cub);
t_img				image_pixel_put(int x, int y, t_img img, t_plan color);

t_win				draw(t_win cub, t_ray r, int x, double r_a);
t_plan				shade(t_plan col, double dist, char way, int in);
void				minimap(t_win cub);

t_win				keys_init(t_win cub);
int					key_rhook(int key, t_win *cub);
int					keyp_hook(int key, t_win *cub);

void				up(t_win **cub);
void				down(t_win **cub);
void				left(t_win **cub);
void				right(t_win **cub);
void				r_up(t_win **cub);
void				r_down(t_win **cub);
void				r_left(t_win **cub);
void				r_right(t_win **cub);
void				escape(t_win **cub);

#endif
