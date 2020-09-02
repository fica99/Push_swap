/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:53 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/24 16:22:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(const char *str)
{
	size_t	i;
	char	is_dig;

	i = 0;
	is_dig = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			if (!ft_isdigit(str[++i]))
				return (0);
		if (!ft_isdigit(str[i]))
		{
			while (ft_isspace(str[i]))
			{
				str = str + i + 1;
				i = 0;
			}
		}
		is_dig = 1;
		++i;
	}
	return (1);
}
