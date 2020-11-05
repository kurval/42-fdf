/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:08:49 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 10:06:13 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	isometric(t_map *map_info, t_pixel *pixel)
{
	int previous_x;
	int previous_y;

	previous_x = pixel->rx;
	previous_y = pixel->ry;
	PIX_IX = SHIFT_X + (previous_x - previous_y) * cos(radian_ang(30));
	PIX_IY = SHIFT_Y + (-pixel->rz +\
	(previous_x + previous_y) * sin(radian_ang(30)));
	pixel->color = set_color(map_info, pixel->pz / ZMOD);
}

static void	conic(t_map *map_info, t_pixel *pixel)
{
	int previous_x;
	int previous_y;

	previous_x = pixel->rx;
	previous_y = pixel->ry;
	PIX_IX = SHIFT_X + previous_x;
	PIX_IY = SHIFT_Y + previous_y;
	pixel->color = set_color(map_info, pixel->pz / ZMOD);
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
			if (map_info->pro == ISO)
				isometric(map_info, PIX);
			else if (map_info->pro == CONIC)
				conic(map_info, PIX);
			x++;
		}
		y++;
	}
}
