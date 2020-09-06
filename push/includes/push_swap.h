/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:09:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/06 11:27:15 by aashara-         ###   ########.fr       */
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
void		ps_sort(t_stack_int *stack_a, t_stack_int *stack_b);
/*
**			ps_sort_other.c
*/
t_bool		ps_equal(int first, int second);
void		ps_rotate(t_stack_int *stack, size_t pos);
void		ps_insert(t_stack_int *stack, int value, int *min, int *max);
#endif
