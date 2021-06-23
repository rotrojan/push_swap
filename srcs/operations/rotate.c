/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 03:00:11 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	if (stack->items != NULL)
	{
		stack->items = stack->items->next;
		stack->top = stack->items;
	}
}

void	rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
