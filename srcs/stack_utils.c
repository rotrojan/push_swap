/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 13:04:11 by bigo             ###   ########.fr       */
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

void	free_stack(t_stack *stack_a)
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
