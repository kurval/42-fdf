/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:08:49 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 22:41:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	metric(t_map *map_info, t_pixel *point)
{
	int		previous_x;
	int		previous_y;
	double	rad;

	rad = (map_info->pro == ISO) ? radian_ang(30) : radian_ang(15);
	previous_x = point->rx;
	previous_y = point->ry;
	POINT_IX = SHIFT_X + (previous_x - previous_y) * cos(rad);
	POINT_IY = SHIFT_Y + (-point->rz +\
	(previous_x + previous_y) * sin(rad));
	point->color = set_color(map_info, point->pz / ZMOD);
}

static void	conic(t_map *map_info, t_pixel *point)
{
	int previous_x;
	int previous_y;

	previous_x = point->rx;
	previous_y = point->ry;
	POINT_IX = SHIFT_X + previous_x;
	POINT_IY = SHIFT_Y + previous_y;
	point->color = set_color(map_info, point->pz / ZMOD);
}

void		projections(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (map_info->pro == ISO || map_info->pro == DIMETRIC)
				metric(map_info, POINT);
			else if (map_info->pro == CONIC)
				conic(map_info, POINT);
			x++;
		}
		y++;
	}
}
