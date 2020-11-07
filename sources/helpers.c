/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:35:43 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/07 11:57:55 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Calculates radian angle from given angle.
*/

double		radian_ang(int angle)
{
	return ((angle * M_PI) / 180);
}

static void	free_map(t_map *map_info)
{
	int y;
	int x;

	y = 0;
	while (map_info->points[y])
	{
		x = 0;
		while (POINT)
		{
			free(POINT);
			x++;
		}
		free(map_info->points[y]);
		y++;
	}
	free(map_info->points);
}

void		free_all(t_map *map_info)
{
	free(map_info->controls);
	free_map(map_info);
}

void		print_error(char *error_msg)
{
	ft_printf(error_msg);
	exit(1);
}

void		print_points(t_map *map_info)
{
	int i;
	int x;

	i = 0;
	while (map_info->points[i])
	{
		x = 0;
		while (map_info->points[i][x])
		{
			ft_printf("%d ", map_info->points[i][x]->pz);
			x++;
		}
		i++;
		ft_printf("\n");
	}
}
