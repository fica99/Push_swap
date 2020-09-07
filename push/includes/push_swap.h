/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:09:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/07 15:55:36 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "checker.h"
# include "libstackint.h"

/*
**			ps_sort.c
*/
void		ps_sort_3(t_stack_int *stack_a);
void		ps_sort(t_stack_int *stack_a, t_stack_int *stack_b);
/*
**			ps_sort_other.c
*/
void		ps_sort_other(t_stack_int *stack_a, t_stack_int *stack_b);
/*
**			ps_rotate.c
*/
void		ps_rotate(t_stack_int *stack, size_t pos, char name);
void		ps_double_rotate(t_stack_int *stack_a, size_t pos_a,
									t_stack_int *stack_b, size_t pos_b);
#endif
