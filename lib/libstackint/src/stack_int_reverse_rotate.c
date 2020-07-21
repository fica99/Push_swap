/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:45:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 11:53:42 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_reverse_rotate(t_stack_int *stack)
{
	t_list_int	*last;
	t_list_int	*head;

	if (stack->size < 2)
		return (False);
	head = stack->stack;
	while (head->next->next)
		head = head->next;
	last = head->next;
	head->next = NULL;
	last->next = stack->stack;
	stack->stack = last;
	return (True);
}
