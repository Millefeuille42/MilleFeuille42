/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:48:59 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/03 17:47:40 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <time.h>

typedef struct s_mov
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	
	double frameTime;
} t_mov;

t_mov mov;

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

int movement(int key)
{
	ft_putnbr_fd(key, 1, 0);
	double moveSpeed = mov.frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = mov.frameTime * 3.0; //the constant value is in radians/second//
	if(keyDown(SDLK_UP))
	{
		if(!(worldMap[(int)(mov.posX + mov.dirX * moveSpeed)][(int)(mov.posY)])) mov.posX += mov.dirX * moveSpeed;
		if(!(worldMap[(int)(mov.posX)][(int)(mov.posY + mov.dirY * moveSpeed)])) mov.posY += mov.dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if(keyDown(SDLK_DOWN))
	{
		if(!(worldMap[(int)(mov.posX - mov.dirX * moveSpeed)][(int)(mov.posY)])) mov.posX -= mov.dirX * moveSpeed;
		if(!(worldMap[(int)(mov.posX)][(int)(mov.posY - mov.dirY * moveSpeed)])) mov.posY -= mov.dirY * moveSpeed;
	}
	//rotate to the right
	if(keyDown(SDLK_RIGHT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = mov.dirX;
		mov.dirX = mov.dirX * cos(-rotSpeed) - mov.dirY * sin(-rotSpeed);
		mov.dirY = oldDirX * sin(-rotSpeed) + mov.dirY * cos(-rotSpeed);
		double oldPlaneX = mov.planeX;
		mov.planeX = mov.planeX * cos(-rotSpeed) - mov.planeY * sin(-rotSpeed);
		mov.planeY = oldPlaneX * sin(-rotSpeed) + mov.planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if(keyDown(SDLK_LEFT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = mov.dirX;
		mov.dirX = mov.dirX * cos(rotSpeed) - mov.dirY * sin(rotSpeed);
		mov.dirY = oldDirX * sin(rotSpeed) + mov.dirY * cos(rotSpeed);
		double oldPlaneX = mov.planeX;
		mov.planeX = mov.planeX * cos(rotSpeed) - mov.planeY * sin(rotSpeed);
		mov.planeY = oldPlaneX * sin(rotSpeed) + mov.planeY * cos(rotSpeed);
	}
}

int	mlx3D(t_cub conf)
{
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

	for(int x = 0; x < conf.res.x; x++)
	{
		ft_putchar_fd( '\n', 1);
		ft_putchar_fd( 'R', 1);
		cameraX = 2 * x / conf.res.x -1;
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
		int lineHeight = (int)(conf.res.y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + conf.res.y / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + conf.res.y / 2;
		if (drawEnd >= conf.res.y) drawEnd = conf.res.y - 1;

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
			mlx_pixel_put(conf.mlxptr, conf.winptr, x, drawStart, color);
			drawStart++;
		}
	}
	oldTime = time;
	time = clock();
	double frameTime = (time - oldTime) / 1000.0;
	
	mov = (t_mov) {
			.posX = posX,
			.posY = posY,
			.dirX = dirX,
			.dirY = dirY,
			.planeX = planeX,
			.planeY = planeY,
			.frameTime = frameTime
	};
	int key = 0;
	mlx_key_hook(conf.winptr, &movement, &key);
	return (0);
}