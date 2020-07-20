/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:41:30 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 20:42:42 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(const char *msg, int is_exit)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (is_exit)
		exit(EXIT_FAILURE);
}
