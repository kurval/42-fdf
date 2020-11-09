/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:37:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/09 16:57:36 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

/*
** Initializing constants and starting point and
** decision variable (ERR).
*/

static void	get_args(t_map *map_info, t_point *start, t_point *end)
{
	DX = ft_abs(END_X - START_X);
	DY = ft_abs(END_Y - START_Y);
	SX = (END_X >= START_X) ? 1 : -1;
	SY = (END_Y >= START_Y) ? 1 : -1;
	X = START_X;
	Y = START_Y;
	ERR = (DX > DY) ? 2 * DY - DX : 2 * DX - DY;
}

/*
** Same as draw_low() but y gets increased in
** each iteration.
*/

static void	draw_high(t_map *map_info, t_point *start, t_point *end)
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

/*
** Increases x in each iteration. Y gets only
** increased if decision variable (ERR) is greater than zero.
** In that case ERR variable gets readjust.
*/

static void	draw_low(t_map *map_info, t_point *start, t_point *end)
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

/*
** Based on a slope we need to increase in each
** iteration either x (draw low) or y (draw high).
*/

static void	draw_line(t_map *map_info, t_point *start, t_point *end)
{
	get_args(map_info, start, end);
	if (DX > DY)
		draw_low(map_info, start, end);
	else
		draw_high(map_info, start, end);
}

/*
** Based on map height and width we have connect
** each endpoints and draw lines in vertical and
** horizontal direction.
*/

void		draw_map(t_map *map_info)
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
				draw_line(map_info, POINT, map_info->points[y][x + 1]);
			if (y < MAP_HEIGHT - 1)
				draw_line(map_info, POINT, map_info->points[y + 1][x]);
			x++;
		}
		y++;
	}
}
