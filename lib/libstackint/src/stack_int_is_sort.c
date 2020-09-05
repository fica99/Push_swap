/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_is_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:06:13 by aashara           #+#    #+#             */
/*   Updated: 2020/09/05 01:08:22 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

t_bool	stack_int_is_sort(t_stack_int *stack)
{
	t_list_int	*head;
	t_list_int	*checker;

	if (stack->empty)
		return (True);
	head = stack->stack;
	while (head->next)
	{
		checker = head->next;
		while (checker)
		{
			if (head->value >= checker->value)
				return (False);
			checker = checker->next;
		}
		head = head->next;
	}
	return (True);
}
