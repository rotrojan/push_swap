/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/30 18:41:19 by rotrojan         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_error			error;

	if (ac < 2)
		return (0);
	{
		error = parse_args(av);
		if (error != NO_ERROR)
			return (exit_error(error));
		sort_stack();
		free_stack(stack_provider(A));
	}
	return (EXIT_SUCCESS);
}
