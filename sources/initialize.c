/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:31:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/03 10:51:28 by vkurkela         ###   ########.fr       */
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
    new_controls->zmod = 2;
    new_controls->shift_x = WIDTH / 4;
    new_controls->shift_y = HEIGHT / 4;
    return (new_controls);
}

void    reset_controls(t_map *info)
{
    info->controls->shift_x = WIDTH / 4;
    info->controls->shift_y = HEIGHT / 4;
    info->controls->zoom = 25;
    info->controls->zmod = 2;
    info->controls->color = 0;
}