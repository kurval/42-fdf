/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:46:15 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 08:38:45 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rot_x(t_pixel *pixel, double ang)
{
	int	y;

	y = pixel->ry;
	pixel->ry = y * cos(ang) + pixel->rz * sin(ang);
	pixel->rz = -y * sin(ang) + pixel->rz * cos(ang);
}

static void	rot_y(t_pixel *pixel, double ang)
{
	int	x;

	x = pixel->rx;
	pixel->rx = x * cos(ang) + pixel->rz * sin(ang);
	pixel->rz = -x * sin(ang) + pixel->rz * cos(ang);
}

static void	rot_z(t_pixel *pixel, double ang)
{
	int	x;
	int	y;

	x = pixel->rx;
	y = pixel->ry;
	pixel->rx = x * cos(ang) - y * sin(ang);
	pixel->ry = x * sin(ang) + y * cos(ang);
}


void	rotate(t_map *map_info)
{
    int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
            RX = PIX_X;
            RY = PIX_Y;
            RZ = PIX_Z;
            RX *= ZOOM;
            RY *= ZOOM;
            RZ *= ZOOM / ZMOD;
            RX -= (MAP_WIDTH * ZOOM) / 2;
            RY -= (MAP_HEIGHT * ZOOM) / 2;
            rot_x(PIX, radian_ang(map_info->controls->x_angle));
            rot_y(PIX, radian_ang(map_info->controls->y_angle));
            rot_z(PIX, radian_ang(map_info->controls->z_angle));
			x++;
		}
		y++;
	}
}