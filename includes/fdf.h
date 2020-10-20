/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/20 10:40:16 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				z;
}					t_pixel;

typedef struct		s_map
{
	t_pixel         ***pixels;
}					t_map;

void    read_input(int arg, char **argc, t_map *map_info);
void    init_map_info(t_map *info);
void    print_error(char *error_msg);

#endif