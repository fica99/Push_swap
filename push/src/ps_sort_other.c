/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:35:04 by aashara           #+#    #+#             */
/*   Updated: 2020/09/07 16:29:57 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool			ps_equal(int first, int second)
{
	return (t_bool)(first == second);
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

static void		ps_insert(t_stack_int *stack_a, t_stack_int *stack_b, int *min,
																	int *max)
{
	size_t		min_i;
	size_t		pos;
	t_list_int	*tmp;
	int			i;

	min_i = ps_find_min_rotation(stack_a, stack_b, *min, *max);
	i = -1;
	tmp = stack_b->stack;
	while ((size_t)++i != min_i)
		tmp = tmp->next;
	if (tmp->value < *min)
	{
		pos = stack_int_find(stack_a, *min, &ps_equal);
		*min = tmp->value;
	}
	else if (tmp->value > *max)
	{
		pos = stack_int_find(stack_a, *max, &ps_equal) + 1;
		*max = tmp->value;
	}
	else
		pos = ps_find_middle_pos(stack_a, tmp->value);
	ps_double_rotate(stack_a, pos, stack_b, min_i);
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
		ps_insert(stack_a, stack_b, &min, &max);
		stack_int_push_to_other(stack_a, stack_b);
		ft_putendl("pa");
	}
	pos = stack_int_find(stack_a, min, &ps_equal);
	ps_rotate(stack_a, pos, 'a');
}
