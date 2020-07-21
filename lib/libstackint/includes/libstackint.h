/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstackint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:28:42 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 11:46:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACKINT_H
# define LIBSTACKINT_H

# include <stddef.h>
# include <stdlib.h>

typedef enum
{
	True = 1,
	False = 0
}	t_bool;

typedef struct			s_list_int
{
	int					value;
	struct s_list_int	*next;
}						t_list_int;

typedef struct			s_stack_int
{
	t_bool				empty;
	size_t				size;
	t_list_int			*stack;
}						t_stack_int;

t_bool					stack_int_push(t_stack_int *stack, int value,
													t_bool check_duplicate);
t_bool					stack_int_pop(t_stack_int *stack);
t_bool					stack_int_swap_first_elems(t_stack_int *stack);
t_bool					stack_int_push_to_other(t_stack_int *stack_a,
						t_stack_int *stack_b);
t_bool					stack_int_rotate(t_stack_int *stack);
t_bool					stack_int_reverse_rotate(t_stack_int *stack);
#endif
