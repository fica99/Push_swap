/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:10:25 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/05 01:11:23 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack_int	stack_a;
	t_stack_int	stack_b;

	if (argc > 1)
	{
		ft_bzero((void*)&stack_a, sizeof(t_stack_int));
		stack_a.empty = True;
		ft_bzero((void*)&stack_b, sizeof(t_stack_int));
		stack_b.empty = True;
		fill_stack(&stack_a, argc, argv, False);
		if (stack_a.size > 1 && stack_int_is_sort(&stack_a) == False)
			ps_sort(&stack_a, &stack_b);
		while (stack_a.empty == False)
			stack_int_pop(&stack_a);
		while (stack_b.empty == False)
			stack_int_pop(&stack_b);
	}
	return (EXIT_SUCCESS);
}

