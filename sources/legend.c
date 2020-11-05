/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:32:07 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 10:46:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    draw_legend(t_map *map_info)
{
    int		y;

	y = 0;
	mlx_string_put(MLX, WIN, 15, y += 20, WHITE, "HOW TO USE");
    mlx_string_put(MLX, WIN, 15, y += 25, TEXT, "Color: 'C' Key");
	mlx_string_put(MLX, WIN, 15, y += 25, TEXT, "Zoom: Scroll Mouse");
	mlx_string_put(MLX, WIN, 15, y += 25, TEXT, "Move: Right Click");
	mlx_string_put(MLX, WIN, 15, y += 25, TEXT, "Altitude: 'A' and 'S' Keys");
	mlx_string_put(MLX, WIN, 15, y += 25, TEXT, "Rotate: Arrow Keys");
	mlx_string_put(MLX, WIN, 15, y += 25, TEXT, "Projections: 1 = ISO 2 = CONIC");
}