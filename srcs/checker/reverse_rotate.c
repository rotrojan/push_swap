/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 20:14:40 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_reverse_rotate(enum e_stack_id stack_id)
{
	t_stack	*stack;

	if (stack_id == A)
		stack = stack_provider(A);
	else
		stack = stack_provider(B);
	if (stack->items != NULL)
	{
		stack->items = stack->items->prev;
		stack->top = stack->items;
	}
	if (stack_id == R)
	{
		stack = stack_provider(A);
		if (stack->items != NULL)
		{
			stack->items = stack->items->prev;
			stack->top = stack->items;
		}
	}
}

void	reverse_rotate_a(void)
{
	checker_reverse_rotate(A);
}

void	reverse_rotate_b(void)
{
	checker_reverse_rotate(B);
}

void	reverse_rotate_r(void)
{
	checker_reverse_rotate(R);
}
