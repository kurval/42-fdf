/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:37:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/28 20:52:17 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void	get_args(t_map *map_info, t_pixel *start, t_pixel *end, int ret)
{
	if (ret == 1)
	{
		map_info->dx = ft_abs(end->ix - start->ix);
		map_info->dy = ft_abs(end->iy - start->iy);
		map_info->sx = (end->ix >= start->ix) ? 1 : -1;
		map_info->sy = (end->iy >= start->iy) ? 1 : -1;
		map_info->x0 = start->ix + map_info->sx;
		map_info->y0 = start->iy;
		map_info->err = 2 * map_info->dy - map_info->dx;
	}
	else
	{
		map_info->dx = ft_abs(end->iy - start->iy);
		map_info->dy = ft_abs(end->ix - start->ix);
		map_info->sx = (end->iy >= start->iy) ? 1 : -1;
		map_info->sy = (end->ix >= start->ix) ? 1 : -1;
		map_info->x0 = start->iy + map_info->sx;
		map_info->y0 = start->ix;
		map_info->err = 2 * map_info->dx - map_info->dy;
	}
}

void    draw_line(t_map *map_info, t_pixel *start, t_pixel *end, int icr)
{
	int i;
	int ret;

	i = 0;
	ret = (ft_abs(end->ix - start->ix) > ft_abs(end->iy - start->iy));
	get_args(map_info, start, end, ret);
	mlx_pixel_put(map_info->mlx, map_info->win, start->ix, end->iy, WHITE);
	while (i++ <= map_info->dx - 1)
	{
		if (map_info->err > 0)
		{
			map_info->y0 += map_info->sy;
			map_info->err = map_info->err + 2 * (map_info->dy + map_info->dx);
		}
		else
			map_info->err = map_info->err + 2 * map_info->dy;
		if (icr == ICR_X)
			mlx_pixel_put(map_info->mlx, map_info->win, map_info->x0, map_info->y0, WHITE);
		else
			mlx_pixel_put(map_info->mlx, map_info->win, map_info->y0, map_info->x0, WHITE);
		map_info->x0 += map_info->sx;
	}
}

void    draw_map(t_map *map_info)
{
    int	x;
	int	y;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (x != map_info->width - 1)
				draw_line(map_info, map_info->pixels[y][x], map_info->pixels[y][x + 1], ICR_X);
			if (y != map_info->height - 1)
				draw_line(map_info, map_info->pixels[y][x], map_info->pixels[y + 1][x], ICR_Y);
			x++;
		}
		y++;
	}
}

void		conic(t_map *map_info)
{
	int	x;
	int	y;
	int strtx;
	int strty;
	double zoom;

	zoom = 25;
	strtx = WIDTH / 4;
	strty = HEIGHT / 4;
	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			map_info->pixels[y][x]->ix = strtx + map_info->pixels[y][x]->px * zoom;
			map_info->pixels[y][x]->iy = strty + map_info->pixels[y][x]->py * zoom;
			x++;
		}
		y++;
	}
	draw_map(map_info);
}