/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:30 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/07 12:19:39 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	expose_hook(t_map *map_info)
{
	draw_legend(map_info);
	rotate(map_info);
	projections(map_info);
	draw_map(map_info);
	return (1);
}

int	main(int args, char **argv)
{
	t_map	map_info;

	init_map_info(&map_info);
	read_input(args, argv, &map_info);
	mlx_expose_hook(map_info.win, expose_hook, &map_info);
	mlx_key_hook(map_info.win, press_key, &map_info);
	mlx_mouse_hook(map_info.win, press_mouse, &map_info);
	mlx_loop(map_info.mlx);
	free_all(&map_info);
	return (0);
}
