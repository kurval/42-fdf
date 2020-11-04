/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:31:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/04 20:16:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

void    init_map_info(t_map *info)
{
    info->pixels = NULL;
    info->controls = init_controls();
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
    info->pro = ISO;
}

t_ctrl  *init_controls(void)
{
    t_ctrl  *new_controls;

    if (!(new_controls = (t_ctrl*)malloc(sizeof(t_ctrl))))
        print_error(MALLOC_ERROR);
    new_controls->zoom = 25;
    new_controls->zmod = 0.02;
    new_controls->shift_x = WIDTH / 2;
    new_controls->shift_y = HEIGHT / 2;
    new_controls->y_angle = 0;
    new_controls->x_angle = 0;
    new_controls->z_angle = 0;
    return (new_controls);
}

void    reset_controls(t_map *info)
{
    info->controls->shift_x = WIDTH / 2;
    info->controls->shift_y = HEIGHT / 2;
    info->controls->zoom = 25;
    info->controls->zmod = 0.02;
    info->controls->color = 0;
    info->controls->y_angle = 0;
    info->controls->x_angle = 0;
    info->controls->z_angle = 0;
}