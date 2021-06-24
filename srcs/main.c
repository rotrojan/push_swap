/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 20:46:05 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_provider(enum e_stack_id stack_id)
{
	static t_stack	stack_a = {
		.items = NULL,
		.top = NULL,
		.size = 0
	};
	static t_stack	stack_b = {
		.items = NULL,
		.top = NULL,
		.size = 0
	};

	if (stack_id == A)
		return (&stack_a);
	else
		return (&stack_b);
}

static void	free_stack(t_stack *stack_a)
{
	t_item		*current;

	if (stack_a->items)
	{
		if (stack_a->top == stack_a->top->next)
		{
			free(stack_a->items);
			ft_bzero(stack_a, sizeof(stack_a));
		}
		else
		{
			current = stack_a->top->next;
			while (current->next != stack_a->top)
			{
				free(current->prev);
				current->prev = NULL;
				current = current->next;
			}
			free(current->prev);
			current->prev = NULL;
			free(current);
			current = NULL;
			stack_a->items = NULL;
		}
	}
}

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
