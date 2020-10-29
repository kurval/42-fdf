/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/29 12:32:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

/*
**	WINDOW SIZE
*/

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

/*
**	MAP MACROS
*/

# define PIX	map_info->pixels[y][x]
# define PIX_X	map_info->pixels[y][x]->px
# define PIX_Y	map_info->pixels[y][x]->py
# define PIX_Z	map_info->pixels[y][x]->pz

# define MLX	map_info->mlx
# define WIN	map_info->win
# define ERR	map_info->err
# define X		map_info->x
# define Y		map_info->y

# define DX		map_info->dx
# define DY		map_info->dy
# define SX		map_info->sx
# define SY		map_info->sy

# define M_HEIGHT	map_info->height
# define M_WIDTH	map_info->width

# define BEG_X		map_info->beg_x
# define BEG_Y		map_info->beg_y

/*
**	CONTROLS
*/

# define ZOOM		map_info->controls->zoom
# define ZMOD		map_info->controls->zmod

typedef struct		s_pixel
{
	int				px;
	int				py;
	int				pz;
	int				color;
	int				ix;
	int				iy;
}					t_pixel;

typedef struct		s_ctrl
{
	double			zoom;
	double			zmod;
}					t_ctrl;

typedef struct		s_map
{
	t_pixel         ***pixels;
	t_ctrl			*controls;
    int             height;
    int             width;
	void			*mlx;
	void			*win;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x;
	int				y;
	int				err;
	int				beg_x;
	int				beg_y;
}					t_map;

int     main(int args, char **argv);
void    read_input(int args, char **argv, t_map *map_info);
void    init_map_info(t_map *info);
void    init_controls(t_map *info);
void    print_error(char *error_msg);
void	free_all(t_map *map_info);
int		press_key(int keycode, t_map *info);
void    draw_line(t_map *map_info, t_pixel *start, t_pixel *end);
int		expose_hook(t_map *map_info);
void    draw_map(t_map *map_info);
void	conic(t_map *map_info);
void	iso(t_map *map_info);

#endif