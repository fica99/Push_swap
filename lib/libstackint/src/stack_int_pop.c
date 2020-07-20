/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:08:38 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 12:20:24 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_pop(t_stack_int *stack)
{
	t_list_int	*next_elem;

	if (stack->empty == True)
		return (False);
	--stack->size;
	if (!stack->size)
		stack->empty = True;
	next_elem = stack->stack->next;
	free(stack->stack);
	stack->stack = next_elem;
	return (True);
}
