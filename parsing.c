/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 20:52:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int exit_error(t_error error, )

t_error	parse_args(char **av)
{
	t_error	error;

	int	i;

	i = 1;
	error = NO_ERROR;
	while (av[i])
	{
		error = check_arg(av[i])

		i++;
	}
	if (check_duplicate = FALSE)
		error =  DUPLICATE_ERROR;
	return (error);
}
