/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:03:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/21 17:21:43 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_error(char *msg, char *argument)
{
	char	buff[ERROR_MESSAGE_SIZE];

	ft_strcpy(buff, "Error: ");
	ft_strcat(buff, msg);
	ft_strcat(buff, ": ");
	ft_strcat(buff, argument);
	ft_perror(buff, True);
}

static int	check_flags(char *str)
{
	size_t	j;
	uint8_t	flags;

	j = 0;
	flags = 0;
	while (str[++j])
	{
		if (str[j] == 'v')
			flags |= V_FLAG;
		else if (str[j] == 'c')
			flags |= C_FLAG;
		else
			print_error(INVALID_ERR, str);
	}
	if (j == 1)
		print_error(INVALID_ERR, str);
	return (flags);
}

static int	parse_flags(int argc, char **argv, uint8_t *flags)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			(*flags) |= check_flags(argv[i]);
		else
		{
			if (!ft_isnum(argv[i]))
				print_error(INVALID_ERR, argv[i]);
			break ;
		}
	}
	return (i - 1);
}

uint8_t		fill_stack(t_stack_int *stack, int argc, char **argv)
{
	int		i;
	uint8_t	flags;

	flags = 0;
	i = parse_flags(argc, argv, &flags);
	while (--argc > i)
	{
		if (ft_isnum(argv[argc]))
		{
			if (stack_int_push(stack, ft_atoi(argv[argc]), True) == False)
				print_error(DUP_ERR, argv[argc]);
		}
		else
			print_error(INVALID_ERR, argv[argc]);
	}
	return (flags);
}
