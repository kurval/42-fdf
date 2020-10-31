/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:37:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/31 12:22:14 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void	get_args(t_map *map_info, t_pixel *start, t_pixel *end)
{
	DX = ft_abs(END_X - START_X);
	DY = ft_abs(END_Y - START_Y);
	SX = (END_X >= START_X) ? 1 : -1;
	SY = (END_Y >= START_Y) ? 1 : -1;
	if (DX > DY)
	{
		X = START_X + SX;
		Y = START_Y;
		ERR = 2 * DY - DX;
	}
	else
	{
		X = START_X;
		Y = START_Y + SY;
		ERR = 2 * DX -  DY;
	}
}

static void    vertical(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int i;

	i = 0;
	mlx_pixel_put(MLX, WIN, START_X, START_Y, \
	get_color(map_info, start, end));
	while (i++ <= DY - 1)
	{
		if (ERR > 0)
		{	
			X += SX;
			ERR = ERR + 2 * DX - 2 * DY;
		}
		else
			ERR = ERR + 2 * DX;
		mlx_pixel_put(MLX, WIN, X, Y, \
		get_color(map_info, start, end));
		Y += SY;
	}
}

static void    horizontal(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int i;

	i = 0;
	mlx_pixel_put(MLX, WIN, START_X, START_Y, \
	get_color(map_info, start, end));
	while (i++ <= DX - 1)
	{
		if (ERR > 0)
		{	
			Y += SY;
			ERR = ERR + 2 * DY - 2 * DX;
		}
		else
			ERR = ERR + 2 * DY;
		mlx_pixel_put(MLX, WIN, X, Y, \
		get_color(map_info, start, end));
		X += SX;
	}
}

static void draw_line(t_map *map_info, t_pixel *start, t_pixel *end)
{
	get_args(map_info, start, end);
	if (DX > DY)
		horizontal(map_info, start, end);
	else
		vertical(map_info, start, end);
}

void    draw_map(t_map *map_info)
{
    int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (x < MAP_WIDTH - 1)
				draw_line(map_info, PIX, map_info->pixels[y][x + 1]);
			if (y < MAP_HEIGHT - 1)
				draw_line(map_info, PIX, map_info->pixels[y + 1][x]);
			x++;
		}
		y++;
	}
}