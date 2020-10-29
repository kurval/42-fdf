/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:37:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 13:05:40 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void	get_args(t_map *map_info, t_pixel *start, t_pixel *end, int ret)
{
	if (ret == 1)
	{
		DX = ft_abs(end->ix - start->ix);
		DY = ft_abs(end->iy - start->iy);
		SX = (end->ix >= start->ix) ? 1 : -1;
		SY = (end->iy >= start->iy) ? 1 : -1;
		X = start->ix + SX;
		Y = start->iy;
		ERR = 2 * DY - DX;
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
	}
}

void    draw_line(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int i;
	int icr;

	i = 0;
	icr = (ft_abs(end->ix - start->ix) > ft_abs(end->iy - start->iy));
	get_args(map_info, start, end, icr);
	while (i++ <= DX - 1)
	{
		if (ERR > 0)
		{
			Y += SY;
			ERR = ERR + 2 * DY - 2 * DX;
		}
		else
			ERR = ERR + 2 * DY;
		if (icr)
			mlx_pixel_put(MLX, WIN, X, Y, WHITE);
		else
			mlx_pixel_put(MLX, WIN, Y, X, WHITE);
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
			if (x != M_WIDTH - 1)
				draw_line(map_info, PIX, map_info->pixels[y][x + 1]);
			if (y != M_HEIGHT - 1)
				draw_line(map_info, PIX, map_info->pixels[y + 1][x]);
			x++;
		}
		y++;
	}
}