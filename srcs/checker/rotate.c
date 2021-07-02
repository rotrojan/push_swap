/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 20:13:57 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker_rotate(enum e_stack_id stack_id)
{
	t_stack	*stack;

	if (stack_id == A)
		stack = stack_provider(A);
	else
		stack = stack_provider(B);
	if (stack->items != NULL)
	{
		stack->items = stack->items->next;
		stack->top = stack->items;
	}
	if (stack_id == R)
	{
		stack = stack_provider(A);
		if (stack->items != NULL)
		{
			stack->items = stack->items->next;
			stack->top = stack->items;
		}
	}
}

void	rotate_a(void)
{
	checker_rotate(A);
}

void	rotate_b(void)
{
	checker_rotate(B);
}

void	rotate_r(void)
{
	checker_rotate(R);
}
