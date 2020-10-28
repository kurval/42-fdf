/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:31:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/28 20:45:58 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init_map_info(t_map *info)
{
    info->pixels = NULL;
    info->height = 0;
    info->width = 0;
    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "Fdf Window");
    info->dx = 0;
	info->dy = 0;
	info->sx = 0;
	info->sy = 0;
	info->x0 = 0;
	info->y0 = 0;
	info->err = 0;
}