/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:06:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/09 16:35:14 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int							ps_atoi(char *str)
{
	int						sign;
	size_t					i;
	long long				rez;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	sign = 1;
	str += i;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	rez = 0;
	while (ft_isdigit(str[i]) && i < 11)
		rez = rez * 10 + str[i++] - '0';
	rez *= sign;
	if (rez > INT_MAX || rez < INT_MIN || i > 11)
		print_error(NUM_OVER, str);
	return ((int)rez);
}
