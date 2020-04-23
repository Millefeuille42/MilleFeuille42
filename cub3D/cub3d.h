/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/13 15:41:21 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define PARAMSNB 8

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_plan
{
	int				r;
	int				g;
	int				b;
}					t_plan;

typedef struct		s_dbl_co
{
	double			x;
	double			y;
}					t_dbl_co;

typedef struct		s_int_co
{
	int				x;
	int				y;
}					t_int_co;

typedef struct		s_img
{
	void			*v_img;
	char			*c_img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_text
{
	t_int_co		size;
	t_img			img;
	char			*path;
	int				fd;
}					t_text;

typedef struct		s_conf
{
	t_res			res;
	t_plan			floor;
	t_plan			roof;
	t_text			no;
	t_text			so;
	t_text			we;
	t_text			ea;
	t_text			sprite;
	char			**map;
	t_dbl_co		pos;
	double			dir_a;
	double			fov;
}					t_conf;

int					cub_parser(int fd, t_conf *conf);
int					graphics(t_conf *conf);

void				deinit_conf(t_conf *conf);

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *hay, const char *ne, size_t len);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
int					atoi_mk2(const char *s, int start, int end);
char				ft_cinset(char c, const char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
