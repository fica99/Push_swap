/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:35:04 by aashara           #+#    #+#             */
/*   Updated: 2020/09/05 03:16:18 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ps_equal(int first, int second)
{
	return (t_bool)(first == second);
}

static t_bool	ps_greater(int first, int second)
{
	return (t_bool)(first > second);
}

static void		ps_rotate(t_stack_int *stack, size_t pos)
{
	t_bool	is_inverse;

	is_inverse = False;
	if (pos > (stack->size / 2))
	{
		pos = stack->size - pos;
		is_inverse = True;
	}
	while (pos--)
	{
		if (is_inverse == True)
		{
			stack_int_reverse_rotate(stack);
			ft_putendl("rra");
		}
		else
		{
			stack_int_rotate(stack);
			ft_putendl("ra");
		}
	}
}

static void		ps_insert(t_stack_int *stack, int value, int *min, int *max)
{
	size_t	pos;

	if (value < *min)
	{
		pos = stack_int_find(stack, *min, &ps_equal);
		*min = value;
	}
	else if (value > *max)
	{
		pos = stack_int_find(stack, *max, &ps_equal) + 1;
		*max = value;
	}
	else
		pos = stack_int_find(stack, value, &ps_greater);
	ps_rotate(stack, pos);

}

void			ps_sort_other(t_stack_int *stack_a, t_stack_int *stack_b)
{
	int		min;
	int		max;
	size_t	pos;

	while (stack_a->size > 3)
	{
		stack_int_push_to_other(stack_b, stack_a);
		ft_putendl("pb");
	}
	ps_sort_3(stack_a);
	min = stack_a->stack->value;
	max = stack_a->stack->next->next->value;
	while (stack_b->empty == False)
	{
		ps_insert(stack_a, stack_b->stack->value, &min, &max);
		stack_int_push_to_other(stack_a, stack_b);
		ft_putendl("pa");
	}
	pos = stack_int_find(stack_a, min, &ps_equal);
	ps_rotate(stack_a, pos);
}
