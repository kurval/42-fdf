/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:39:59 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/01 12:58:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void set_zoom(int button, int x, int y, t_map *map_info)
{
    if (button == 4)
        map_info->controls->zoom += 1;
    if (button == 5)
        map_info->controls->zoom -= 1;
    mlx_clear_window(MLX, WIN);
    expose_hook(map_info);
}

int    press_mouse(int button, int x, int y, t_map *map_info)
{
    if (button == 4 || button == 5)
        set_zoom(button, x, y, map_info);
    return (1);
}