/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:01:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 16:26:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

static t_bool	find_duplicate(t_list_int *list, int value)
{
	t_list_int	*head;

	head = list;
	while (head)
	{
		if (head->value == value)
			return (True);
		head = head->next;
	}
	return (False);
}

t_bool			stack_int_push(t_stack_int *stack, int value,
										t_bool check_duplicate)
{
	t_list_int	*new_elem;

	if (check_duplicate)
	{
		if (find_duplicate(stack->stack, value))
			return (False);
	}
	if (stack->size == 0)
		stack->empty = False;
	++stack->size;
	if (!(new_elem = (t_list_int*)malloc(sizeof(t_list_int))))
		return (False);
	new_elem->value = value;
	new_elem->next = stack->stack;
	stack->stack = new_elem;
	return (True);
}
