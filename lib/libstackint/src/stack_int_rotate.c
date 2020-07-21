/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:37:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 11:44:19 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_rotate(t_stack_int *stack)
{
	t_list_int	*head;
	t_list_int	*next;

	if (stack->size < 2)
		return (False);
	head = stack->stack;
	stack->stack = head->next;
	head->next = NULL;
	next = stack->stack;
	while (next->next)
		next = next->next;
	next->next = head;
	return (True);
}
