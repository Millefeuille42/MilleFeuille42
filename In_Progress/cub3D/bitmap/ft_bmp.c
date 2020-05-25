/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:00:04 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 20:00:04 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bitmap.h"

static inline void	write_img_to_bitmap(t_conf *conf, t_img img, int fd)
{
	int x;
	int y;
	int img_index;

	y = conf->res.y;
	while (y)
	{
		x = 0;
		while (x < conf->res.x)
		{
			img_index = (y * img.sl + x * (img.bpp / 8));
			write(fd, &img.c_img[img_index], (img.bpp / 8));
			x++;
		}
		y--;
	}
}

static inline void	write_bmp_header(t_bmp_info info, int fd)
{
	static int			pixel_offset = 54;
	static int			header_size = 40;
	static int			none = 0;
	static short int	planes = 1;

	write(fd, "BM", 2);
	write(fd, &info.size, sizeof(int));
	write(fd, &none, sizeof(int));
	write(fd, &pixel_offset, sizeof(int));
	write(fd, &header_size, sizeof(int));
	write(fd, &info.width, sizeof(int));
	write(fd, &info.height, sizeof(int));
	write(fd, &planes, sizeof(short int));
	write(fd, &info.bpp, sizeof(short int));
	write(fd, &none, sizeof(int));
	write(fd, &none, sizeof(int));
	write(fd, &none, sizeof(int));
	write(fd, &none, sizeof(int));
	write(fd, &none, sizeof(int));
	write(fd, &none, sizeof(int));
}

static inline void	ft_bmp(t_conf *conf, t_img img)
{
	int			fd;
	t_bmp_info	info;

	if ((fd = open("save.bmp", 01 | 0100,
			(0400 | 0200 | 0100) | 01000)) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Can't open save file\n", 2);
		exit(-1);
	}
	info.height = conf->res.y;
	info.width = conf->res.x;
	info.size = 54 + conf->res.y * img.sl;
	info.bpp = (short int)img.bpp;
	write_bmp_header(info, fd);
	write_img_to_bitmap(conf, img, fd);
}

void				save(t_conf *conf)
{
	t_win		cub;

	cub = (t_win) {.conf = conf};
	cub = keys_init(cub);
	cub.mlx = mlx_init();
	init_textures(&cub);
	cub.img = create_image(cub);
	raycasting(&cub);
	ft_bmp(conf, cub.img);
	mlx_destroy_image(cub.mlx, cub.conf->no.i.v_img);
	mlx_destroy_image(cub.mlx, cub.conf->so.i.v_img);
	mlx_destroy_image(cub.mlx, cub.conf->we.i.v_img);
	mlx_destroy_image(cub.mlx, cub.conf->ea.i.v_img);
	mlx_destroy_image(cub.mlx, cub.conf->sprite.i.v_img);
	mlx_destroy_image(cub.mlx, cub.img.v_img);
	deinit_conf(cub.conf);
	exit(0);
}
