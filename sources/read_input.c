/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:19:28 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/20 10:43:01 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error.h"

void    read_input(int arg, char **argc, t_map *map_info)
{
    if (arg != 2)
        print_error(USAGE);
    ft_printf("YES\n");
}