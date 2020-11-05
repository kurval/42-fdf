/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 10:44:00 by vkurkela         ###   ########.fr       */
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

# define TEXT		0xff00ff
# define WHITE		0xffffff
# define TOP		0x0000ff
# define HIGHMID	0x0080ff
# define HIGH	 	0x00ffff
# define GROUND		0x40ff00
# define LOW	 	0xffff00
# define LOWMID	 	0xff8000
# define BOTTOM	 	0xff0000

/*
**	MAP MACROS
*/

# define MLX		map_info->mlx
# define WIN		map_info->win
# define MAP_HEIGHT	map_info->height
# define MAP_WIDTH	map_info->width

# define PIX		map_info->pixels[y][x]
# define PIX_X		map_info->pixels[y][x]->px
# define PIX_Y		map_info->pixels[y][x]->py
# define PIX_Z		map_info->pixels[y][x]->pz
# define RY			map_info->pixels[y][x]->ry
# define RX			map_info->pixels[y][x]->rx
# define RZ			map_info->pixels[y][x]->rz
# define COLOR		map_info->pixels[y][x]->color

# define PIX_IX		pixel->ix
# define PIX_IY		pixel->iy
# define START_X	start->ix
# define START_Y	start->iy
# define END_X		end->ix
# define END_Y		end->iy

# define ERR		map_info->err
# define X			map_info->x
# define Y			map_info->y
# define DX			map_info->dx
# define DY			map_info->dy
# define SX			map_info->sx
# define SY			map_info->sy

/*
**	CONTROLS
*/

# define ZOOM		map_info->controls->zoom
# define ZMOD		map_info->controls->zmod
# define SHIFT_X	map_info->controls->shift_x
# define SHIFT_Y	map_info->controls->shift_y
# define X_ANGLE	map_info->controls->x_angle
# define Y_ANGLE	map_info->controls->y_angle
# define Z_ANGLE	map_info->controls->z_angle
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
	double			ry;
	double			rx;
	double			rz;
}					t_pixel;

typedef struct		s_ctrl
{
	double			zoom;
	double			zmod;
	int				shift_x;
	int				shift_y;
	int				color;
	int				y_angle;
	int				x_angle;
	int				z_angle;
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
}					t_map;

int     main(int args, char **argv);
void    read_input(int args, char **argv, t_map *map_info);
void    init_map_info(t_map *info);
t_ctrl  *init_controls(void);
void    print_error(char *error_msg);
void	free_all(t_map *map_info);
int		press_key(int keycode, t_map *map_info);
int		expose_hook(t_map *map_info);
void    draw_map(t_map *map_info);
void    reset_controls(t_map *info);
int 	get_color(t_map *map_info, t_pixel *start, t_pixel *end);
int    	set_color(t_map *map_info, int z);
int    	press_mouse(int button, int x, int y, t_map *map_info);
void	rotate(t_map *map_info);
double	radian_ang(int angle);
void	projections(t_map *map_info);
void	print_points(t_map *map_info);
void    draw_legend(t_map *map_info);

#endif