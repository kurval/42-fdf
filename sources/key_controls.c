/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:53:25 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/02 10:59:32 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void set_altitude(int keycode, t_map *map_info)
{
    if (keycode == 97)
        map_info->controls->zmod += 1;
    else if (keycode == 115)
        map_info->controls->zmod -= 1;
    mlx_clear_window(MLX, WIN);
    expose_hook(map_info);
}

static void set_projections(int keycode, t_map *map_info)
{
    if (keycode == 49)
        map_info->pro = ISO;
    else if (keycode == 50)
        map_info->pro = CONIC;
    mlx_clear_window(MLX, WIN);
    expose_hook(map_info);
}

static void set_color_mode(t_map *map_info)
{
    map_info->controls->color = (!map_info->controls->color);
    mlx_clear_window(MLX, WIN);
    expose_hook(map_info);
}

int    press_key(int keycode, t_map *map_info)
{
    ft_printf("key %d\n", keycode);
    if (keycode == ESC)
        exit(0);
    else if (keycode >= 49 && keycode <= 50)
        set_projections(keycode, map_info);
    else if (keycode == 97 || keycode == 115)
        set_altitude(keycode, map_info);
    else if (keycode == 99)
        set_color_mode(map_info);  
    else if (keycode == 100)
    {
        reset_controls(map_info);
        mlx_clear_window(MLX, WIN);
        expose_hook(map_info);
    }
    return (1);
}