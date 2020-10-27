/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:45:29 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/26 14:46:01 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

void    draw_line(t_map *map_info, int x0, int y0, int x1, int y1, int color)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			mlx_pixel_put(map_info->mlx, map_info->win, x, y, color);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			mlx_pixel_put(map_info->mlx, map_info->win, x, y, color);
			p=p+2*dy;
		}
		x=x+1;
	}
}