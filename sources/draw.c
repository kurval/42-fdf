/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:37:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/06 20:46:02 by vkurkela         ###   ########.fr       */
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
	X = START_X;
	Y = START_Y;
	ERR = (DX > DY) ? 2 * DY - DX : 2 * DX - DY;
}

static void	draw_high(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int i;

	i = 0;
	while (i++ <= DY)
	{
		mlx_pixel_put(MLX, WIN, X, Y, \
				get_color(map_info, start, end));
		if (ERR > 0)
		{
			X += SX;
			ERR = ERR + 2 * (DX - DY);
		}
		else
			ERR = ERR + 2 * DX;
		Y += SY;
	}
}

static void	draw_low(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int i;

	i = 0;
	while (i++ <= DX)
	{
		mlx_pixel_put(MLX, WIN, X, Y, \
				get_color(map_info, start, end));
		if (ERR > 0)
		{
			Y += SY;
			ERR = ERR + 2 * (DY - DX);
		}
		else
			ERR = ERR + 2 * DY;
		X += SX;
	}
}

static void	draw_line(t_map *map_info, t_pixel *start, t_pixel *end)
{
	get_args(map_info, start, end);
	if (DX > DY)
		draw_low(map_info, start, end);
	else
		draw_high(map_info, start, end);
}

void		draw_map(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	draw_legend(map_info);
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (x < MAP_WIDTH - 1)
				draw_line(map_info, POINT, map_info->points[y][x + 1]);
			if (y < MAP_HEIGHT - 1)
				draw_line(map_info, POINT, map_info->points[y + 1][x]);
			x++;
		}
		y++;
	}
}
