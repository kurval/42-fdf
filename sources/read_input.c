/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:19:28 by vkurkela          #+#    #+#             */
/*   Updated: 2020/11/05 22:41:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

static int	check_width(t_map *map_info, char **values, int line_num)
{
	int	x;

	x = 0;
	while (values[x])
		x++;
	if (x == 0 || (line_num > 0 && x != map_info->width))
		print_error(MAP_ERROR);
	if (x > map_info->width)
		map_info->width = x;
	return (x);
}

static void	store_values(char **values, t_map *map_info, int y)
{
	int x;
	int	width;

	x = 0;
	width = check_width(map_info, values, y);
	if (!(map_info->points[y] = \
	(t_pixel **)malloc(sizeof(t_pixel *) * width + 1)))
		print_error(MALLOC_ERROR);
	while (values[x] != NULL)
	{
		if (!(POINT = (t_pixel *)malloc(sizeof(t_pixel))))
			print_error(MALLOC_ERROR);
		POINT_X = x;
		POINT_Y = y;
		if (!(ft_atoi_err(values[x])))
			print_error(MAP_ERROR);
		POINT_Z = ft_atoi(values[x]);
		free(values[x]);
		x++;
	}
	free(values);
	POINT = NULL;
}

static void	save_lines(int fd, t_map *map_info, char *file1)
{
	char	**values;
	int		ret;
	char	*line;
	int		line_num;

	ret = 1;
	line = NULL;
	line_num = 0;
	if ((fd = open(file1, O_RDONLY)) == -1)
		print_error(OPEN_ERROR);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		values = ft_strsplit(line, ' ');
		store_values(values, map_info, line_num);
		free(line);
		line_num++;
	}
	close(fd);
	map_info->points[line_num] = NULL;
	free(line);
	if (ret == -1)
		print_error(GNL_ERROR);
}

static void	count_height(int fd, t_map *map_info)
{
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		map_info->height++;
		free(line);
	}
	free(line);
	if (ret == -1)
		print_error(GNL_ERROR);
}

void		read_input(int args, char **argv, t_map *map_info)
{
	int fd;

	fd = 0;
	if (args == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			print_error(OPEN_ERROR);
		count_height(fd, map_info);
		close(fd);
	}
	else
		print_error(USAGE);
	if (!(map_info->points = (t_pixel ***)malloc(sizeof(t_pixel **)\
	* map_info->height + 1)))
		print_error(MALLOC_ERROR);
	save_lines(fd, map_info, argv[1]);
}
