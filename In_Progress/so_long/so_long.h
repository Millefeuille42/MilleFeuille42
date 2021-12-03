/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:49 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:49 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 22/06/2021.
//

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/fcntl.h>
# include <stdio.h>

# include "mlx/X.h"
# include "mlx/mlx.h"
# include "utils/GNL/get_next_line.h"
# include "utils/lists/lists.h"

# define MAP_SET "01CEP"
# define MAP_SUB_SET "CEP"
# define WIN_NAME "so_long"
# define SCREEN_X 1200
# define SCREEN_Y 800

# if __APPLE__

#  define UP		126
#  define LEFT	124
#  define DOWN	125
#  define RIGHT	123
#  define ESCAPE	53

# else

#  define UP		65362
#  define LEFT	65361
#  define DOWN	65364
#  define RIGHT	65363
#  define ESCAPE	65307

# endif

typedef enum e_colors {
	VOID,
	WALL,
	COLL,
	EXIT,
	PLAY,
}				t_colors_e;

typedef struct s_ivec {
	int	x;
	int	y;
}				t_ivec;

typedef struct s_col {
	int	r;
	int	g;
	int	b;
}				t_col;

typedef struct s_img {
	void	*v_img;
	char	*c_img;
	int		bpp;
	int		sl;
	int		endian;
}				t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
}			t_mlx;

typedef struct s_app
{
	int			config_fd;
	int			mov_num;
	int			set[4];
	t_list		map;
	t_mlx		mlx;
	t_col		colors[5];
}				t_app;

int				free_map(t_element *el);

void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			ft_cinset(char c, const char *set);
int				get_charset_index(char c, char *set);
size_t			ft_strlen(const char *str);

int				get_and_check_arguments(int argc, char **argv);
int				get_and_check_map(t_app *app);

int				check_map_char(t_app *app);
int				check_map_walls(t_app *app);

int				app_start_window(t_app *app);

t_img			image_pixel_put(t_ivec d, t_img i, t_col c);
t_img			create_image(t_app app);

int				key_press_hook(int key, t_app *app);
int				quit(t_app *app);
int				update(t_app *app);

void			edit_player_pos(t_app *app, t_ivec dest);
t_ivec			get_player_pos(t_app *app);

void			m_left(t_app *app);
void			m_right(t_app *app);
void			m_up(t_app *app);
void			m_down(t_app *app);

#endif
