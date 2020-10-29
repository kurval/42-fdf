/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:31:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 13:54:02 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

void    init_map_info(t_map *info)
{
    info->pixels = NULL;
    info->controls = NULL;
    info->height = 0;
    info->width = 0;
    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "Fdf Window");
    info->dx = 0;
	info->dy = 0;
	info->sx = 0;
	info->sy = 0;
	info->x = 0;
	info->y = 0;
	info->err = 0;
    info->beg_x = WIDTH / 4;
    info->beg_y = HEIGHT / 4;
}

void    init_controls(t_map *info)
{
    t_ctrl  *new_controls;

    if (!(new_controls = (t_ctrl*)malloc(sizeof(t_ctrl))))
        print_error(MALLOC_ERROR);
    new_controls->zoom = 25;
    new_controls->zmod = 2;
    info->controls = new_controls;
}