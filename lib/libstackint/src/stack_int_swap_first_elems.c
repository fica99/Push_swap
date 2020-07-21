/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_swap_first_elems.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:08:14 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 11:19:39 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_swap_first_elems(t_stack_int *stack)
{
	t_list_int	*next;
	t_list_int	*next_next;

	if (stack->size < 2)
		return (False);
	next = stack->stack->next;
	next_next = next->next;
	stack->stack->next = next_next;
	next->next = stack->stack;
	stack->stack = next;
	return (True);
}
