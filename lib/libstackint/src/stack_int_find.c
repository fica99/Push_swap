/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara <aashara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:07:33 by aashara           #+#    #+#             */
/*   Updated: 2020/09/05 02:15:53 by aashara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstackint.h"

size_t	stack_int_find(t_stack_int *stack, int value, t_bool (*f)(int, int))
{
	size_t		i;
	t_list_int	*tmp;

	i = 0;
	if (stack->empty)
		return (0);
	tmp = stack->stack;
	while (tmp)
	{
		if (f(tmp->value, value))
			break;
		tmp = tmp->next;
		++i;
	}
	return (i);
}
