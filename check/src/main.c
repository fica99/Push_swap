/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:42:11 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 21:13:04 by aashara-         ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	t_stack_int	stack;

	(void)argv;
	if (argc > 1)
	{
		ft_bzero((void*)&stack, sizeof(t_stack_int));
		fill_stack(&stack, argc, argv);
	}
	return (EXIT_SUCCESS);
}
