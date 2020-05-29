/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICAL_H
# define GRAPHICAL_H

# include "cub3d.h"
# include <X11/X.h>

# define TPI 0.017453292519943295

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
	int				keyl[7];
}					t_key;

typedef struct		s_ray
{
	t_dvec			dir;
	t_dvec			dist;
	t_dvec			sdist;
	t_dvec			origin;
	t_ivec			mpos;
	t_ivec			step;
	char			side;
	char			hit;
}					t_ray;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_conf			*conf;
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

int					raycasting(t_win *cub);

t_img				create_image(t_win cub);
t_img image_pixel_put(int x, int y, t_img i, t_col c, t_res res);

t_win				draw(t_win c, t_ray r, int x);
t_col				shade_plane(t_col col, double dist, int in, int y);
t_col				shade_text(t_col col, double dist);

void				minimap(t_win cub);

void				init_textures(t_win *cub);
t_col				text_spot(t_ray hit, t_text t, double y, t_draw lim);
t_win				sp_draw(t_win cub, t_sprite sprite);
t_win				sp_draw_2(t_win cub, t_sprite sprite);

t_win				sprites_calculations(t_win cub);
void				tag_sprite(t_ivec ray, t_sprite *sprites, char sp);

void				reset_buffer(t_win *cub);

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
