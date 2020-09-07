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
	t_bool		is_inverse;

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

static size_t	ps_find_min_rotation(t_stack_int *stack_a,
								t_stack_int *stack_b, int min, int max)
{
	size_t		pos[stack_b->size];
	t_list_int	*tmp;
	size_t		i;
	size_t		min_i;

	tmp = stack_b->stack;
	i = 0;
	min_i = 0;
	while (tmp)
	{
		if (tmp->value < min)
			pos[i] = stack_int_find(stack_a, min, &ps_equal);
		else if (tmp->value > max)
			pos[i] = stack_int_find(stack_a, max, &ps_equal) + 1;
		else
			pos[i] = ps_find_middle_pos(stack_a, tmp->value);
		if (pos[i] > (stack_a->size / 2))
			pos[i] = stack_a->size - pos[i];
		pos[i] += (i > stack_b->size / 2) ? (stack_b->size - i) : i;
		if (pos[i] < pos[min_i])
			min_i = i;
		tmp = tmp->next;
		++i;
	}
	return (min_i);
}

void			ps_insert(t_stack_int *stack_a, t_stack_int *stack_b, int *min,
																	int *max)
{
	size_t		min_i;
	int			value;
	size_t		pos;

	min_i = ps_find_min_rotation(stack_a, stack_b, *min, *max);
	ps_rotate(stack_b, min_i);
	value = stack_b->stack->value;
	if (value < *min)
	{
		pos = stack_int_find(stack_a, *min, &ps_equal);
		*min = value;
	}
	else if (value > *max)
	{
		pos = stack_int_find(stack_a, *max, &ps_equal) + 1;
		*max = value;
	}
	else
		pos = ps_find_middle_pos(stack_a, value);
	ps_rotate(stack_a, pos);
}
