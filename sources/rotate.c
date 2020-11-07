/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:46:15 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/07 12:07:17 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rot_x(t_pixel *point, double ang)
{
	int	y;

	y = point->ry;
	point->ry = y * cos(ang) + point->rz * sin(ang);
	point->rz = -y * sin(ang) + point->rz * cos(ang);
}

static void	rot_y(t_pixel *point, double ang)
{
	int	x;

	x = point->rx;
	point->rx = x * cos(ang) + point->rz * sin(ang);
	point->rz = -x * sin(ang) + point->rz * cos(ang);
}

static void	rot_z(t_pixel *point, double ang)
{
	int	x;
	int	y;

	x = point->rx;
	y = point->ry;
	point->rx = x * cos(ang) - y * sin(ang);
	point->ry = x * sin(ang) + y * cos(ang);
}

/*
** Using rotation matrix to get new coordinates
** for each point. Centering RX and RY before
** rotation.
*/

void		rotate(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			RX = POINT_X;
			RY = POINT_Y;
			RZ = POINT_Z;
			RX *= ZOOM;
			RY *= ZOOM;
			RZ *= ZOOM / ZMOD;
			RX -= (MAP_WIDTH * ZOOM) / 2;
			RY -= (MAP_HEIGHT * ZOOM) / 2;
			rot_x(POINT, radian_ang(X_ANGLE));
			rot_y(POINT, radian_ang(Y_ANGLE));
			rot_z(POINT, radian_ang(Z_ANGLE));
			x++;
		}
		y++;
	}
}
