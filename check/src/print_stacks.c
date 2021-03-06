/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:40:37 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/06 10:37:35 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_head(void)
{
	ft_putstr(" __________________________ \n");
	ft_putstr("|             |            |\n");
	ft_putstr("|      a      |     b      |\n");
	ft_putstr("|             |            |\n");
	ft_putstr("|_____________|____________|\n");
}

static void	print_nums(t_stack_int *stack_a, t_stack_int *stack_b)
{
	int			big_size;
	t_list_int	*head_a;
	t_list_int	*head_b;

	big_size = ft_max(stack_a->size, stack_b->size) + 1;
	head_a = stack_a->stack;
	head_b = stack_b->stack;
	while (--big_size)
	{
		if (head_a)
		{
			ft_printf("|  {cyan}%-11d{eoc}|", head_a->value);
			head_a = head_a->next;
		}
		else
			ft_printf("|             |");
		if (head_b)
		{
			ft_printf(" {cyan}%-11d{eoc}|\n", head_b->value);
			head_b = head_b->next;
		}
		else
			ft_printf("            |\n");
	}
}

void		print_stacks(t_stack_int *stack_a, t_stack_int *stack_b)
{
	print_head();
	print_nums(stack_a, stack_b);
	ft_putstr("|_____________|____________|\n");
}
