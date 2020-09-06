/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:06:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/06 11:36:17 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static unsigned int			get_num(char *str, size_t i)
{
	unsigned int			rez;

	rez = 0;
	while (ft_isdigit(str[i]))
	{
		rez = rez * 10 + str[i++] - '0';
		if (rez > INT_MAX)
			print_error(NUM_OVER, str);
	}
	return (rez);
}

int							ps_atoi(char *str)
{
	int						sign;
	size_t					i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		if (!ft_isdigit(str[i]))
			print_error(INVALID_ERR, str);
	}
	return (sign * get_num(str, i));
}
