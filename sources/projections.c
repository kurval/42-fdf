/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:08:49 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 09:47:00 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        isometric(t_map *map_info)
{
    int	x;
	int	y;
	int previous_x;
	int previous_y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			previous_x = RX;
			previous_y = RY;
			PIX_IX = SHIFT_X + (previous_x - previous_y) * cos(radian_ang(30));
			PIX_IY = SHIFT_Y + ((-RZ) + (previous_x + previous_y) * sin(radian_ang(30)));
            COLOR = set_color(map_info, PIX_Z / ZMOD);
			x++;
		}
		y++;
	}
}

void		conic(t_map *map_info)
{
	int	x;
	int	y;
	int previous_x;
	int previous_y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			previous_x = RX;
			previous_y = RY;
			PIX_IX = SHIFT_X + previous_x;
			PIX_IY = SHIFT_Y + previous_y;
            COLOR = set_color(map_info, PIX_Z / ZMOD);
			x++;
		}
		y++;
	}
}

int			expose_hook(t_map *map_info)
{
	rotate(map_info);
    if (map_info->pro == ISO)
	    isometric(map_info);
    else if (map_info->pro == CONIC)
        conic(map_info);
    draw_map(map_info);
	return (1);
}