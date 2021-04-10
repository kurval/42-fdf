/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:39:46 by vkurkela          #+#    #+#             */
/*   Updated: 2021/04/10 13:09:38 by vkurkela         ###   ########.fr       */
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
# define BOTTOM		0x0000ff
# define LOWMID		0x0080ff
# define LOW	 	0x00ffff
# define GROUND		0x40ff00
# define HIGH	 	0xffff00
# define HIGHMID	 	0xff8000
# define TOP 	0xff0000

/*
**	MAP MACROS
*/

# define MLX		map_info->mlx
# define WIN		map_info->win
# define MAP_HEIGHT	map_info->height
# define MAP_WIDTH	map_info->width

# define POINT		map_info->points[y][x]
# define POINT_X	map_info->points[y][x]->px
# define POINT_Y	map_info->points[y][x]->py
# define POINT_Z	map_info->points[y][x]->pz
# define RY			map_info->points[y][x]->ry
# define RX			map_info->points[y][x]->rx
# define RZ			map_info->points[y][x]->rz
# define COLOR		map_info->points[y][x]->color

# define POINT_IX	point->ix
# define POINT_IY	point->iy
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
# define DIMETRIC	2
# define CONIC		3

typedef struct		s_point
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
}					t_point;

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
	t_point			***points;
	t_ctrl			*controls;
	int				pro;
	int				height;
	int				width;
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

int					main(int args, char **argv);
void				read_input(int args, char **argv, t_map *map_info);
void				init_map_info(t_map *info);
t_ctrl				*init_controls(void);
void				print_error(char *error_msg);
void				free_all(t_map *map_info);
int					press_key(int keycode, t_map *map_info);
int					expose_hook(t_map *map_info);
void				draw_map(t_map *map_info);
void				reset_controls(t_map *info);
int					get_color(t_map *map_info, t_point *start, t_point *end);
int					set_color(t_map *map_info, int z);
int					press_mouse(int button, int x, int y, t_map *map_info);
void				rotate(t_map *map_info);
double				radian_ang(int angle);
void				projections(t_map *map_info);
void				print_points(t_map *map_info);
void				draw_legend(t_map *map_info);

#endif
