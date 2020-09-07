/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:18:31 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/07 15:59:59 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_rotate(t_stack_int *stack, size_t pos, char name)
{
	t_bool		is_inverse;
	char		command[4];
	size_t		i;

	i = 0;
	is_inverse = False;
	command[i++] = 'r';
	if (pos > (stack->size / 2))
	{
		pos = stack->size - pos;
		is_inverse = True;
		command[i++] = 'r';
	}
	command[i++] = name;
	command[i++] = '\0';
	while (pos--)
	{
		if (is_inverse == True)
			stack_int_reverse_rotate(stack);
		else
			stack_int_rotate(stack);
		ft_putendl(command);
	}
}

static void		ps_rotate_double_reverse(t_stack_int *stack_a, size_t pos_a,
										t_stack_int *stack_b, size_t pos_b)
{
	pos_a = stack_a->size - pos_a;
	pos_b = stack_b->size - pos_b;
	while (pos_a && pos_b)
	{
		--pos_a;
		--pos_b;
		stack_int_reverse_rotate(stack_a);
		stack_int_reverse_rotate(stack_b);
		ft_putendl("rrr");
	}
	while (pos_b--)
	{
		stack_int_reverse_rotate(stack_b);
		ft_putendl("rrb");
	}
	while (pos_a--)
	{
		stack_int_reverse_rotate(stack_a);
		ft_putendl("rra");
	}
}

static void		ps_rotate_double(t_stack_int *stack_a, size_t pos_a,
										t_stack_int *stack_b, size_t pos_b)
{
	while (pos_a && pos_b)
	{
		--pos_a;
		--pos_b;
		stack_int_rotate(stack_a);
		stack_int_rotate(stack_b);
		ft_putendl("rr");
	}
	while (pos_b--)
	{
		stack_int_rotate(stack_b);
		ft_putendl("rb");
	}
	while (pos_a--)
	{
		stack_int_rotate(stack_a);
		ft_putendl("ra");
	}
}

void			ps_double_rotate(t_stack_int *stack_a, size_t pos_a,
										t_stack_int *stack_b, size_t pos_b)
{
	t_bool		is_inverse_a;
	t_bool		is_inverse_b;

	is_inverse_a = False;
	if (pos_a > (stack_a->size / 2))
		is_inverse_a = True;
	is_inverse_b = False;
	if (pos_b > (stack_b->size / 2))
		is_inverse_b = True;
	if (is_inverse_a != is_inverse_b)
	{
		ps_rotate(stack_b, pos_b, 'b');
		ps_rotate(stack_a, pos_a, 'a');
	}
	else
	{
		if (is_inverse_a == True)
			ps_rotate_double_reverse(stack_a, pos_a, stack_b, pos_b);
		else
			ps_rotate_double(stack_a, pos_a, stack_b, pos_b);
	}
}
