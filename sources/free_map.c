/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:37:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 12:12:46 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void    free_map(t_map *map_info)
{
    int i;
	int x;

	i = 0;
	while (map_info->pixels[i])
	{	
		x = 0;
		while (map_info->pixels[i][x])
        {
			free(map_info->pixels[i][x]);
			x++;
		}
        free(map_info->pixels[i]);
		i++;
	}
    free(map_info->pixels);
}

void	free_all(t_map *map_info)
{
	free(map_info->controls);
	free_map(map_info);
}