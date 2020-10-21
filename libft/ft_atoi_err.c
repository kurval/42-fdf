/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:29:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/10/21 13:01:08 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		starting_point(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static	int		check_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		*i += 1;
	}
	return (str[*i]);
}

int				ft_atoi_err(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = starting_point(str);
	if (!check_sign(str, &i, &sign))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else if (str[i] == ',')
			break ;
		else
			return (0);
		i++;
	}
	res = sign * res;
	return (res <= 2147483647 && res >= -2147483648);
}
