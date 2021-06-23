/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 03:01:40 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	if (stack->items != NULL)
	{
		stack->items = stack->items->prev;
		stack->top = stack->items;
	}
}

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
