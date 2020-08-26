/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_first_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 20:10:03 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/26 22:46:24 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_3_greater(t_stack_int *stack_a)
{
	t_list_int	*head;

	head = stack_a->stack;
	if (head->next->value > head->next->next->value)
	{
		stack_int_swap_first_elems(stack_a);
		stack_int_reverse_rotate(stack_a);
		ft_putendl("sa");
		ft_putendl("rra");
	}
	else
	{
		if (head->value > head->next->next->value)
		{
			stack_int_rotate(stack_a);
			ft_putendl("ra");
		}
		else
		{
			stack_int_swap_first_elems(stack_a);
			ft_putendl("sa");
		}
	}
}

static void	ps_sort_3(t_stack_int *stack_a)
{
	t_list_int	*head;

	head = stack_a->stack;
	if (head->value > head->next->value)
		ps_sort_3_greater(stack_a);
	else
	{
		if (head->value > head->next->next->value)
		{
			stack_int_reverse_rotate(stack_a);
			ft_putendl("rra");
		}
		else if (head->next->value > head->next->next->value)
		{
			stack_int_swap_first_elems(stack_a);
			stack_int_rotate(stack_a);
			ft_putendl("sa");
			ft_putendl("ra");
		}
	}
}

static void	ps_sort_2(t_stack_int *stack_a)
{
	t_list_int	*head;

	head = stack_a->stack;
	if (head->value > head->next->value)
	{
		stack_int_swap_first_elems(stack_a);
		ft_putendl("sa");
	}
}

static void ps_sort_4(t_stack_int *stack_a, t_stack_int *stack_b)
{
	ps_sort_3(stack_a);
	stack_int_push_to_other(stack_b, stack_a);
	ft_putendl("pb");
	ps_sort_3(stack_a);
	stack_int_push_to_other(stack_a, stack_b);
	ft_putendl("pa");
}

void		ps_sort_first_5(t_stack_int *stack_a, t_stack_int *stack_b)
{
	if (stack_a->size == 2)
		ps_sort_2(stack_a);
	else if (stack_a->size == 3)
		ps_sort_3(stack_a);
	else if (stack_a->size == 4)
		ps_sort_4(stack_a, stack_b);
	else
	{
		
	}
}
