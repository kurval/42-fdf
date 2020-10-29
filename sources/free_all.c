/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:37:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 13:09:51 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void    free_map(t_map *map_info)
{
    int y;
	int x;

	y = 0;
	while (map_info->pixels[y])
	{	
		x = 0;
		while (PIX)
        {
			free(PIX);
			x++;
		}
        free(map_info->pixels[y]);
		y++;
	}
    free(map_info->pixels);
}

void	free_all(t_map *map_info)
{
	free(map_info->controls);
	free_map(map_info);
}