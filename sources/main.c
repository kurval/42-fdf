/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:30 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/26 17:56:33 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			expose_hook(t_map *map_info)
{
	draw_line(map_info, 0, 0, 100, 100, WHITE);
    draw_line(map_info, 200, 200, 1000, 0, RED);
    draw_line(map_info, 200, 400, 1000, 0, LIME);
	return (1);
}

int main(int args, char **argv)
{
    t_map   map_info;

    init_map_info(&map_info);
    read_input(args, argv, &map_info);
    mlx_expose_hook(map_info.win, expose_hook, &map_info);
    mlx_key_hook(map_info.win, press_key, &map_info);
    mlx_loop(map_info.mlx);
    free_map(&map_info);
    return (0);
}
