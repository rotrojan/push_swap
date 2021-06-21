/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 20:27:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_usage(void)
{
	ft_printf("Usage:   ./push_swap <integers_list> ...\n");
	ft_printf("Example: ./push_swap 18 4 -986 654 -12 0\n");
}

int	main(int ac, char **av)
{
	t_error	error;

		(void)av;
	if (ac < 2)
		print_usage();
	else
	{
		error = parse_args();
		if (!= NO_ERROR)
			return (exit_error(error));
	}
	return (0);
}
