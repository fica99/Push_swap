/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:42:11 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 13:15:35 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	fill_stack(t_stack_int *stack, int argc, char **argv)
{
	int		i;
	char	msg[ERROR_MESSAGE_SIZE];

	i = 0;
	while (++i < argc)
	{
		if (ft_isnum(argv[i]))
		{
			if (stack_int_push(stack, ft_atoi(argv[i]), True) == False)
			{
				ft_strcpy(msg, "Error: incorrect insertion of a number into");
				ft_strcat(msg, " the stack (possibly a duplicate): ");
				ft_strcat(msg, argv[i]);
				ft_perror(msg, True);
			}
		}
		else
		{
			ft_strcpy(msg, "Error: Invalid argument: ");
			ft_strcat(msg, argv[i]);
			ft_perror(msg, True);
		}
	}
}

static void	check_command(char *buffer, t_stack_int *stack_a,
												t_stack_int *stack_b)
{
	if (buffer[0] == 's')
		check_s_commands(buffer, stack_a, stack_b);
	else if (buffer[0] == 'p')
		check_p_commands(buffer, stack_a, stack_b);
	else if (buffer[0] == 'r')
		check_r_commands(buffer, stack_a, stack_b);
	else
		ft_perror("Error: incorrect command", True);
}

static void	read_commands(t_stack_int *stack_a, t_stack_int *stack_b)
{
	char	*buffer;
	int		res;

	while ((res = get_next_line(0, &buffer)) > 0)
	{
		check_command(buffer, stack_a, stack_b);
		ft_strdel(&buffer);
	}
	if (res == -1)
		ft_perror("Error: read()", True);
}

int			main(int argc, char **argv)
{
	t_stack_int	stack_a;
	t_stack_int	stack_b;

	(void)argv;
	if (argc > 1)
	{
		ft_bzero((void*)&stack_a, sizeof(t_stack_int));
		stack_a.empty = True;
		ft_bzero((void*)&stack_b, sizeof(t_stack_int));
		stack_b.empty = True;
		fill_stack(&stack_a, argc, argv);
		read_commands(&stack_a, &stack_b);
	}
	return (EXIT_SUCCESS);
}
