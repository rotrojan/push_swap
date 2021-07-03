/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 22:53:43 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_error			error;

	if (ac < 2)
		return (0);
	{
		error = parse_args(av);
		if (error != NO_ERROR)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		order_stack(A);
		sort_stack(A);
		free_stack(A);
	}
	return (EXIT_SUCCESS);
}
