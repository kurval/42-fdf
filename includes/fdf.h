/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/26 18:03:09 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH	1920
# define HEIGHT	1080
# define ESC	65307

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pixel;

typedef struct		s_map
{
	t_pixel         ***pixels;
    int             height;
    int             width;
	void			*mlx;
	void			*win;
}					t_map;

int     main(int args, char **argv);
void    read_input(int args, char **argv, t_map *map_info);
void    init_map_info(t_map *info);
void    print_error(char *error_msg);
void    free_map(t_map *map_info);
int		press_key(int keycode, t_map *info);

#endif