/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 13:05:33 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exit_error(t_error error)
{
	static char	*error_message[ERROR_MAX] = {
		NULL,
		DUPLICATE_ERROR_STR,
		NON_DIGIT_ERROR_STR,
		OUT_OF_RANGE_ERROR_STR,
		MALLOC_FAILURE_ERROR_STR
	};

	free_stack(stack_provider(A));
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", error_message[error]);
	return (EXIT_FAILURE);
}

static void	print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage:   ./push_swap <integers_list> ...\n");
	ft_dprintf(STDERR_FILENO, "Example: ./push_swap 18 4 -986 654 -12 0\n");
}

int	main(int ac, char **av)
{
	t_error			error;

	if (ac < 2)
		print_usage();
	else
	{
		error = parse_args(av);
		if (error != NO_ERROR)
			return (exit_error(error));
		sort_stack();
		free_stack(stack_provider(A));
	}
	return (EXIT_SUCCESS);
}
