/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:30 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/20 10:44:05 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int arg, char **argc)
{
    t_map   map_info;

    init_map_info(&map_info);
    read_input(arg, argc, &map_info);

    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
    mlx_loop(mlx);
    return (0);
}
