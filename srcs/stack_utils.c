/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 03:27:33 by bigo             ###   ########.fr       */
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

void	free_stack(enum e_stack_id stack_id)
{
	t_stack		*stack;
	t_item		*current;

	stack = stack_provider(stack_id);
	if (stack->items)
	{
		if (stack->top == stack->top->next)
		{
			free(stack->items);
			ft_bzero(stack, sizeof(*stack));
		}
		else
		{
			current = stack->top->next;
			while (current->next != stack->top)
			{
				free(current->prev);
				current = current->next;
			}
			free(current->prev);
			free(current);
			current = NULL;
			ft_bzero(stack, sizeof(*stack));
		}
	}
}

void	order_stack(enum e_stack_id stack_id)
{
	int				mini;
	t_item			*current;
	unsigned int	order;
	t_bool			stop_flag;
	t_stack			*stack;

	mini = get_mini(stack_id);
	order = 0;
	stack = stack_provider(stack_id);
	while (order < stack->size)
	{
		current = stack->top;
		stop_flag = FALSE;
		while (current->nb != mini && stop_flag == FALSE)
		{
			current = current->next;
			if (current == stack->top)
				stop_flag = TRUE;
		}
		if (stop_flag == FALSE)
			current->order = order++;
		++mini;
	}
}
