/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:08:49 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/30 11:12:05 by vkurkela         ###   ########.fr       */
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
			PIX_IX = SHIFT_X + ((PIX_X - PIX_Y) * cos(0.866025)) * ZOOM;
			PIX_IY = SHIFT_Y + (-PIX_Z * ZMOD) + ((PIX_X + PIX_Y) \
            * sin(0.5)) * ZOOM;
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
			x++;
		}
		y++;
	}
}