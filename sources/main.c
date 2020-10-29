/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:30 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 19:29:25 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			expose_hook(t_map *map_info)
{
    if (map_info->pro == ISO)
	    isometric(map_info);
    else if (map_info->pro == CONIC)
        conic(map_info);
	return (1);
}

int main(int args, char **argv)
{
    t_map   map_info;

    init_map_info(&map_info);
    init_controls(&map_info);
    read_input(args, argv, &map_info);
    mlx_expose_hook(map_info.win, expose_hook, &map_info);
    mlx_key_hook(map_info.win, press_key, &map_info);
    mlx_loop(map_info.mlx);
    free_all(&map_info);
    return (0);
}
