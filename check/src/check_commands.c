/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:49:38 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 13:12:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_s_commands(char *buffer, t_stack_int *stack_a,
											t_stack_int *stack_b)
{
	if (ft_strequ(buffer + 1, "a"))
		stack_int_swap_first_elems(stack_a);
	else if (ft_strequ(buffer + 1, "b"))
		stack_int_swap_first_elems(stack_b);
	else if (ft_strequ(buffer + 1, "s"))
	{
		stack_int_swap_first_elems(stack_a);
		stack_int_swap_first_elems(stack_b);
	}
	else
		ft_perror("Error: incorrect command", True);
}

void	check_p_commands(char *buffer, t_stack_int *stack_a,
											t_stack_int *stack_b)
{
	if (ft_strequ(buffer + 1, "a"))
		stack_int_push_to_other(stack_a, stack_b);
	else if (ft_strequ(buffer + 1, "b"))
		stack_int_push_to_other(stack_b, stack_a);
	else
		ft_perror("Error: incorrect command", True);
}

void	check_r_commands(char *buffer, t_stack_int *stack_a,
											t_stack_int *stack_b)
{
	if (ft_strequ(buffer + 1, "a"))
		stack_int_rotate(stack_a);
	else if (ft_strequ(buffer + 1, "b"))
		stack_int_rotate(stack_b);
	else if (buffer[1] == 'r')
	{
		if (buffer[2] == '\0')
		{
			stack_int_rotate(stack_a);
			stack_int_rotate(stack_b);
		}
		else if (ft_strequ(buffer + 2, "a"))
			stack_int_reverse_rotate(stack_a);
		else if (ft_strequ(buffer + 2, "b"))
			stack_int_reverse_rotate(stack_b);
		else if (ft_strequ(buffer + 2, "r"))
		{
			stack_int_reverse_rotate(stack_a);
			stack_int_reverse_rotate(stack_b);
		}
		else
			ft_perror("Error: incorrect command", True);
	}
	else
		ft_perror("Error: incorrect command", True);
}
