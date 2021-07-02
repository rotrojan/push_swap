/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 20:13:12 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker_swap(enum e_stack_id stack_id)
{
	t_item	*item;
	t_stack	*stack;

	stack = stack_provider(stack_id);
	if (stack->items != NULL)
	{
		item = stack->top->next;
		take_item(item, stack);
		put_item(item, stack);
	}	
	if (stack_id == S)
	{
		if (stack->items != NULL)
		{
			stack = stack_provider((stack_id + 1) % 2);
			item = stack->top->next;
			take_item(item, stack);
			put_item(item, stack);
		}
	}
}

void	swap_a(void)
{
	checker_swap(A);
}

void	swap_b(void)
{
	checker_swap(B);
}

void	swap_s(void)
{
	checker_swap(S);
}
