/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:31:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/26 17:56:00 by vkurkela         ###   ########.fr       */
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
}