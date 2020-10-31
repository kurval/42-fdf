/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/31 12:22:30 by vkurkela         ###   ########.fr       */
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

# define ESC		65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

/*
**	COLORS
*/

# define WHITE 	0xffffff
# define RED	0xff0000
# define LIME	0x00ff00

/*
**	MAP MACROS
*/

# define PIX		map_info->pixels[y][x]
# define PIX_X		map_info->pixels[y][x]->px
# define PIX_Y		map_info->pixels[y][x]->py
# define PIX_Z		map_info->pixels[y][x]->pz
# define PIX_IX		map_info->pixels[y][x]->ix
# define PIX_IY		map_info->pixels[y][x]->iy
# define COLOR		map_info->pixels[y][x]->color
# define START_X	start->ix
# define START_Y	start->iy
# define END_X		end->ix
# define END_Y		end->iy

# define MLX		map_info->mlx
# define WIN		map_info->win
# define ERR		map_info->err
# define X			map_info->x
# define Y			map_info->y

# define DX			map_info->dx
# define DY			map_info->dy
# define SX			map_info->sx
# define SY			map_info->sy

# define MAP_HEIGHT	map_info->height
# define MAP_WIDTH	map_info->width

# define SHIFT_X	map_info->shift_x
# define SHIFT_Y	map_info->shift_y

/*
**	CONTROLS
*/

# define ZOOM		map_info->controls->zoom
# define ZMOD		map_info->controls->zmod
# define ISO		1
# define CONIC		2

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
	int				pro;
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
	int				shift_x;
	int				shift_y;
	int				axis;
}					t_map;

int     main(int args, char **argv);
void    read_input(int args, char **argv, t_map *map_info);
void    init_map_info(t_map *info);
void    init_controls(t_map *info);
void    print_error(char *error_msg);
void	free_all(t_map *map_info);
int		press_key(int keycode, t_map *map_info);
int		expose_hook(t_map *map_info);
void    draw_map(t_map *map_info);
void	conic(t_map *map_info);
void	isometric(t_map *map_info);
void    reset_controls(t_map *info);
int 	get_color(t_map *map_info, t_pixel *start, t_pixel *end);
int		set_color(t_pixel *pixel);

#endif