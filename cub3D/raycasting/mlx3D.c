/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:48:59 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/04 16:25:42 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



int worldMap[24][24]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

void			ft_putnbr_fd(unsigned long int n, int fd, char flag)
{
	long int	nb;

	if (fd < 0)
		return ;
	nb = (int)n;
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd, 0);
		nb = nb % 10;
	}
	nb = nb + 48;
	write(fd, &nb, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int movement(int key, t_mov *mov)
{
	ft_putnbr_fd(key, 1, 0);
	double movespeed = mov->frameTime * 5.0; //the constant value is in squares/second
	double  rotspped = mov->frameTime * 3.0; //the constant value is in radians/second//
	ft_putchar_fd('\n', 1);

	if (key == 53)
	{
		deinit_conf(mov->conf);
		exit(0);
	}

	if(key == 126)
	{
		if(!(worldMap[(int)(mov->posX + mov->dirX * 1)][(int)(mov->posY)])) mov->posX += mov->dirX * 1;
		if(!(worldMap[(int)(mov->posX)][(int)(mov->posY + mov->dirY * 1)])) mov->posY += mov->dirY * 1;
	}
	//move backwards if no wall behind you
	if(key == 125)
	{
		if(!(worldMap[(int)(mov->posX - mov->dirX * 1)][(int)(mov->posY)])) mov->posX -= mov->dirX * 1;
		if(!(worldMap[(int)(mov->posX)][(int)(mov->posY - mov->dirY * 1)])) mov->posY -= mov->dirY * 1;
	}
	//rotate to the right
	if(key == 124)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = mov->dirX;
		mov->dirX = mov->dirX * cos(-0.5) - mov->dirY * sin(-0.5);
		mov->dirY = oldDirX * sin(-0.5) + mov->dirY * cos(-0.5);
		double oldPlaneX = mov->planeX;
		mov->planeX = mov->planeX * cos(-0.5) - mov->planeY * sin(-0.5);
		mov->planeY = oldPlaneX * sin(-0.5) + mov->planeY * cos(-0.5);
	}
	//rotate to the left
	if(key == 123)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = mov->dirX;
		mov->dirX = mov->dirX * cos(0.5) - mov->dirY * sin(0.5);
		mov->dirY = oldDirX * sin(0.5) + mov->dirY * cos(0.5);
		double oldPlaneX = mov->planeX;
		mov->planeX = mov->planeX * cos(0.5) - mov->planeY * sin(0.5);
		mov->planeY = oldPlaneX * sin(0.5) + mov->planeY * cos(0.5);
	}
	mlx3D(mov->conf);
	return (0);
}

t_mov	mlx3D(t_cub *conf)
{
	t_mov mov;

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	double posX = 13, posY = 13;  //x and y start position
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double cameraX;

	double rayDirX;
	double rayDirY;

	int mapX;
	int mapY;

	double sideDistX;
	double sideDistY;

	for(int x = 0; x < conf->res.x; x++)
	{
		ft_putchar_fd( '\n', 1);
		ft_putchar_fd( 'R', 1);
		cameraX = 2 * x / conf->res.x -1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		mapX = (int)posX;
		mapY = (int)posY;
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
		double perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side = 0; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		ft_putchar_fd( 'D', 1);
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			ft_putchar_fd('P', 1);
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapX - posX + (float)(1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - posY + (float)(1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(conf->res.y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + conf->res.y / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + conf->res.y / 2;
		if (drawEnd >= conf->res.y) drawEnd = conf->res.y - 1;

		//choose wall color
		int color;
		color = 255;

		//give x and y sides different brightness
		if (side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line

		ft_putnbr_fd(drawStart, 1, 0);
		ft_putchar_fd( '\n', 1);
		ft_putnbr_fd(drawEnd, 1, 0);
		ft_putchar_fd( '\n', 1);

		while (drawStart != drawEnd)
		{
			if (drawStart%2)
			{
				ft_putnbr_fd(drawStart, 1, 0);
				ft_putchar_fd( '\n', 1);
			}
			//mlx_pixel_put(conf->mlxptr, conf->winptr, x, drawStart, color);
			drawStart++;
		}
	}
	oldTime = time;
	time = clock();
	double frameTime = (time - oldTime) / 1000.0;
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd((int)frameTime, 2, 0);
	mov = (t_mov) {
			.posX = posX,
			.posY = posY,
			.dirX = dirX,
			.dirY = dirY,
			.planeX = planeX,
			.planeY = planeY,
			.frameTime = frameTime,
			.conf = conf
	};
	return (mov);
}

int niktoi(t_cub *conf)
{
	t_mov mov;

	mov = mlx3D(conf);
	movement(126, &mov);
	movement(125, &mov);
	movement(124, &mov);
	movement(123, &mov);
	//mlx_key_hook(conf->winptr, &movement, &mov);
	return (0);
}