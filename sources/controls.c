/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:53:25 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 19:27:19 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

int    press_key(int keycode, t_map *map_info)
{
    ft_printf("key %d\n", keycode);
    if (keycode == ESC)
        exit(0);
    else if (keycode == 49)
    {
        map_info->pro = ISO;
        mlx_clear_window(MLX, WIN);
        expose_hook(map_info);
    }
    else if (keycode == 50)
    {
        map_info->pro = CONIC;
        mlx_clear_window(MLX, WIN);
        expose_hook(map_info);
    }
    return (1);
}