/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:08:49 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/30 17:27:02 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        isometric(t_map *map_info)
{
    int	x;
	int	y;

	y = 0;
	while (y < M_HEIGHT)
	{
		x = 0;
		while (x < M_WIDTH)
		{
			PIX_IX = SHIFT_X + ((PIX_X - PIX_Y) * cos(0.523599)) * ZOOM;
			PIX_IY = SHIFT_Y + (-PIX_Z * ZMOD) + ((PIX_X + PIX_Y) \
            * sin(0.523599)) * ZOOM;
            COLOR = set_color(PIX);
			x++;
		}
		y++;
	}
}

void		conic(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < M_HEIGHT)
	{
		x = 0;
		while (x < M_WIDTH)
		{
			PIX_IX = SHIFT_X + PIX_X * ZOOM;
			PIX_IY = SHIFT_Y + PIX_Y * ZOOM;
            COLOR = set_color(PIX);
			x++;
		}
		y++;
	}
}