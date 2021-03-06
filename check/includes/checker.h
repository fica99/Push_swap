/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:44:14 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/06 11:37:04 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libstackint.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define ERROR_MESSAGE_SIZE 128
# define V_FLAG 1
# define DUP_ERR_FIRST "Incorrect insertion of a number into the stack"
# define DUP_ERR_SECOND " (possibly a duplicate)"
# define DUP_ERR DUP_ERR_FIRST DUP_ERR_SECOND
# define INVALID_ERR "Invalid argument"
# define NUM_OVER "Number overflow"

/*
**	check_commands.c
*/
void		check_s_commands(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b);
void		check_p_commands(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b);
void		check_r_commands(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b);
/*
**	print_stacks.c
*/
void		print_stacks(t_stack_int *stack_a, t_stack_int *stack_b);
/*
**	fill_stack.c
*/
void		print_error(char *msg, char *argument);
uint8_t		fill_stack(t_stack_int *stack, int argc, char **argv,
													t_bool is_flags);
/*
**	ps_atoi.c
*/
int			ps_atoi(char *str);
#endif
