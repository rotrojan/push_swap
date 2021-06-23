/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 18:29:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	exit_error(t_error error, t_stack *stack_a)
{
	static char	*error_message[Error_max] = {
		NULL,
		DUPLICATE_ERROR_STR,
		NON_DIGIT_ERROR_STR,
		OUT_OF_RANGE_ERROR_STR,
		MALLOC_FAILURE_ERROR_STR
	};

	free_stack(stack_a);
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", error_message[error]);
	return (EXIT_FAILURE);
}

static void	print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage:   ./push_swap <integers_list> ...\n");
	ft_dprintf(STDERR_FILENO, "Example: ./push_swap 18 4 -986 654 -12 0\n");
}

/*
*/
void	print_stack(t_stack *stack_a)
{
	t_item	*current;

	current = stack_a->items;
	if (current == NULL)
	{
		ft_printf("%p\n", current);
		return ;
	}
	ft_printf("%d\n", current->nb);
	current = current->next;
	while (current != stack_a->top)
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_error			error;
	t_stack			stack_a;
	t_stack			stack_b;

	if (ac < 2)
		print_usage();
	else
	{
		ft_bzero(&stack_a, sizeof(stack_a));
		ft_bzero(&stack_b, sizeof(stack_b));
		error = parse_args(av, &stack_a);
		if (error != No_error)
			return (exit_error(error, &stack_a));
		/* print_stack(&stack_a); */
		sort_stack(&stack_a, &stack_b);
		free_stack(&stack_a);
	}
	return (EXIT_SUCCESS);
}
