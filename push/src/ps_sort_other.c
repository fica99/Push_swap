/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:35:04 by aashara           #+#    #+#             */
/*   Updated: 2020/09/05 18:48:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool			ps_equal(int first, int second)
{
	return (t_bool)(first == second);
}

void			ps_rotate(t_stack_int *stack, size_t pos)
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

static size_t	ps_find_middle_pos(t_stack_int *stack, int value)
{
	size_t		pos;
	t_list_int	*tmp;

	pos = 1;
	tmp = stack->stack;
	while (tmp->next)
	{
		if (tmp->value < value && tmp->next->value > value)
			break ;
		tmp = tmp->next;
		++pos;
	}
	return (pos);
}

void			ps_insert(t_stack_int *stack, int value, int *min, int *max)
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
		pos = ps_find_middle_pos(stack, value);
	ps_rotate(stack, pos);
}
