/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:01:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/19 20:28:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_push(t_stack_int *stack, int value)
{
	t_list_int	*new_elem;

	if (stack->size == 0)
		stack->empty = False;
	++stack->size;
	if (!(new_elem = (t_list_int*)malloc(sizeof(t_list_int))))
		return False;
	new_elem->value = value;
	new_elem->next = stack->stack;
	stack->stack = new_elem;
	return True;
}
