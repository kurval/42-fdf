/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:14:01 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/31 12:06:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

int    set_color(t_pixel *pixel)
{
	int color;

	color = 0;
	color = (pixel->pz) ? RED : LIME;
	return (color);
}

static double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

static int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_map *map_info, t_pixel *start, t_pixel *end)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (start->color == end->color)
        return (end->color);
    percentage = (DX > DY) ? percent(START_X, END_X, X) : \
    percent(START_Y, END_Y, Y);
    red = get_light((start->color >> 16) & 0xFF, (end->color >> 16) & 0xFF, percentage);
    green = get_light((start->color >> 8) & 0xFF, (end->color >> 8) & 0xFF, percentage);
    blue = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}