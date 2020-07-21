/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:44:14 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 13:13:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libstackint.h"
# include "libft.h"
# include "get_next_line.h"

# define ERROR_MESSAGE_SIZE 128

/*
**	check_commands.c
*/
void	check_s_commands(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b);
void	check_p_commands(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b);
void	check_r_commands(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b);
#endif
