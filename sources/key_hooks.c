/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:53:25 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/07 12:52:23 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static void	set_altitude(int keycode, t_map *map_info)
{
	if (keycode == 97)
		map_info->controls->zmod -= 1;
	else if (keycode == 115)
		map_info->controls->zmod += 1;
	if (map_info->controls->zmod < 1)
		map_info->controls->zmod = 1;
	else if (map_info->controls->zmod > 100)
		map_info->controls->zmod = 100;
	mlx_clear_window(MLX, WIN);
	expose_hook(map_info);
}

static void	set_projections(int keycode, t_map *map_info)
{
	if (keycode == 49)
		map_info->pro = ISO;
	else if (keycode == 50)
		map_info->pro = DIMETRIC;
	else if (keycode == 51)
		map_info->pro = CONIC;
	mlx_clear_window(MLX, WIN);
	expose_hook(map_info);
}

static void	set_color_mode(t_map *map_info)
{
	map_info->controls->color = (!map_info->controls->color);
	mlx_clear_window(MLX, WIN);
	expose_hook(map_info);
}

static void	set_angle(int keycode, t_map *map_info)
{
	if (keycode == KEY_LEFT)
		map_info->controls->y_angle -= 5;
	else if (keycode == KEY_RIGHT)
		map_info->controls->y_angle += 5;
	else if (keycode == KEY_UP)
		map_info->controls->x_angle -= 5;
	else if (keycode == KEY_DOWN)
		map_info->controls->x_angle += 5;
	mlx_clear_window(MLX, WIN);
	expose_hook(map_info);
}

int			press_key(int keycode, t_map *map_info)
{
	if (keycode == ESC)
	{
		free_all(map_info);
		exit(0);
	}
	else if (keycode >= 49 && keycode <= 51)
		set_projections(keycode, map_info);
	else if (keycode == 97 || keycode == 115)
		set_altitude(keycode, map_info);
	else if (keycode == 99)
		set_color_mode(map_info);
	else if (keycode >= KEY_LEFT && keycode <= KEY_DOWN)
		set_angle(keycode, map_info);
	else if (keycode == 100)
	{
		reset_controls(map_info);
		mlx_clear_window(MLX, WIN);
		expose_hook(map_info);
	}
	return (1);
}
