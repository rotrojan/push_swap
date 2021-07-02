/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 17:47:30 by bigo             ###   ########.fr       */
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
		sort_stack();
		free_stack(A);
	}
	return (EXIT_SUCCESS);
}
