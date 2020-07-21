/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:21:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 17:06:02 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				++i;
				if (!str[i])
					return (0);
				continue ;
			}
		}
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}
