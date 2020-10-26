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

int main(int args, char **argv)
{
    t_map   map_info;

    init_map_info(&map_info);
    read_input(args, argv, &map_info);
    mlx_key_hook(map_info.win, press_key, &map_info);
    mlx_loop(map_info.mlx);
    free_map(&map_info);
    return (0);
}
