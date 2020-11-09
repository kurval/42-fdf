/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:39:59 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/09 16:46:36 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

static void	set_zoom(int button, t_map *map_info)
{
	if (button == 4)
		map_info->controls->zoom += 1;
	if (button == 5)
		map_info->controls->zoom -= 1;
	if (map_info->controls->zoom < 1)
		map_info->controls->zoom = 1;
	mlx_clear_window(MLX, WIN);
	expose_hook(map_info);
}

static int	set_position(int x, int y, t_map *map_info)
{
	SHIFT_X = x;
	SHIFT_Y = y;
	mlx_clear_window(MLX, WIN);
	expose_hook(map_info);
	return (1);
}

int			press_mouse(int button, int x, int y, t_map *map_info)
{
	if (button == 4 || button == 5)
		set_zoom(button, map_info);
	else if (button == 1)
		set_position(x, y, map_info);
	return (1);
}
