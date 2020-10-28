/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/28 20:43:14 by vkurkela         ###   ########.fr       */
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

/*
**	KEYS
*/

# define ESC	65307

/*
**	COLORS
*/

# define WHITE 	16777215
# define RED	16711680
# define LIME	65280

# define ICR_X	1
# define ICR_Y	2

typedef struct		s_pixel
{
	int				px;
	int				py;
	int				pz;
	int				color;
	int				ix;
	int				iy;
}					t_pixel;

typedef struct		s_map
{
	t_pixel         ***pixels;
    int             height;
    int             width;
	void			*mlx;
	void			*win;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x0;
	int				y0;
	int				err;
}					t_map;

int     main(int args, char **argv);
void    read_input(int args, char **argv, t_map *map_info);
void    init_map_info(t_map *info);
void    print_error(char *error_msg);
void    free_map(t_map *map_info);
int		press_key(int keycode, t_map *info);
void    draw_line(t_map *map_info, t_pixel *start, t_pixel *end, int incr);
int		expose_hook(t_map *map_info);
void    draw_map(t_map *map_info);
void	conic(t_map *map_info);

#endif