/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_push_to_other.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:22:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 11:31:40 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_push_to_other(t_stack_int *stack_a, t_stack_int *stack_b)
{
	t_list_int	*head_b;

	if (stack_b->empty == True)
		return (False);
	head_b = stack_b->stack;
	stack_b->stack = stack_b->stack->next;
	--stack_b->size;
	if (!stack_b->size)
		stack_b->empty = True;
	head_b->next = stack_a->stack;
	stack_a->stack = head_b;
	if (stack_a->empty == True)
		stack_a->empty = False;
	++stack_a->size;
	return (True);
}
