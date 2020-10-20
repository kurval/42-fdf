/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:30 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/20 14:08:00 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int args, char **argv)
{
    t_map   map_info;

    init_map_info(&map_info);
    read_input(args, argv, &map_info);

    /*
    ** This is for testing window
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
    mlx_loop(mlx);
    */
    return (0);
}
