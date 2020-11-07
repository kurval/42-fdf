/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:14:01 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/07 12:16:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

/*
** Setting color based on current altitude.
** Deault color is white.
*/

int				set_color(t_map *map_info, int z)
{
	if (!map_info->controls->color)
		return (WHITE);
	else
	{
		if (z >= 8 || z <= -8)
			return ((z >= 8) ? TOP : BOTTOM);
		else if (z >= 4 || z <= -4)
			return ((z >= 4) ? HIGHMID : LOWMID);
		else if (z >= 1 || z <= -1)
			return ((z >= 1) ? HIGH : LOW);
		else
			return (GROUND);
	}
}

/*
** Calculationg current position in percentages.
*/

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

/*
** Calculating color gradient between start
** and end colors for creating fading effect.
*/

int				get_color(t_map *map_info, t_pixel *start, t_pixel *end)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (start->color == end->color)
		return (end->color);
	percentage = (DX > DY) ? percent(START_X, END_X, X) :\
	percent(START_Y, END_Y, Y);
	r = get_light((start->color >> 16) & 0xFF,\
	(end->color >> 16) & 0xFF, percentage);
	g = get_light((start->color >> 8) & 0xFF,\
	(end->color >> 8) & 0xFF, percentage);
	b = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
