/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:37:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/30 18:40:45 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void	put_pixel(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int color;

	color = get_color(map_info, start, end);
	if (AXIS == AX_X)
		mlx_pixel_put(MLX, WIN, X, Y, color);
	else
		mlx_pixel_put(MLX, WIN, Y, X, color);
}

static int	get_args(t_map *map_info, t_pixel *start, t_pixel *end)
{
	if ((ft_abs(end->ix - start->ix) > ft_abs(end->iy - start->iy)))
	{
		DX = ft_abs(end->ix - start->ix);
		DY = ft_abs(end->iy - start->iy);
		SX = (end->ix >= start->ix) ? 1 : -1;
		SY = (end->iy >= start->iy) ? 1 : -1;
		X = start->ix + SX;
		Y = start->iy;
		ERR = 2 * DY - DX;
		return (AX_X);
	}
	else
	{
		DX = ft_abs(end->iy - start->iy);
		DY = ft_abs(end->ix - start->ix);
		SX = (end->iy >= start->iy) ? 1 : -1;
		SY = (end->ix >= start->ix) ? 1 : -1;
		X = start->iy + SX;
		Y = start->ix;
		ERR = 2 * DX - DY;
		return (AX_Y);
	}
}

static void    draw_line(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int i;

	i = 0;
	AXIS = get_args(map_info, start, end);
	if (map_info->pro == ISO)
		mlx_pixel_put(MLX, WIN, start->ix, start->iy, \
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
		put_pixel(map_info, start, end);
		X += SX;
	}
}

void    draw_map(t_map *map_info)
{
    int	x;
	int	y;

	y = 0;
	while (y < M_HEIGHT)
	{
		x = 0;
		while (x < M_WIDTH)
		{
			if (x < M_WIDTH - 1)
				draw_line(map_info, PIX, map_info->pixels[y][x + 1]);
			if (y < M_HEIGHT - 1)
				draw_line(map_info, PIX, map_info->pixels[y + 1][x]);
			x++;
		}
		y++;
	}
}