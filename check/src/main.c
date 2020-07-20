/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:42:11 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 16:28:37 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack_int	stack;

	(void)argv;
	if (argc > 1)
	{
		ft_bzero((void*)&stack, sizeof(t_stack_int));
		// fill_stack(&stack, argc, argv);
	}
	return (EXIT_SUCCESS);
}
