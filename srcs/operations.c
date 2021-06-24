/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 20:37:00 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(enum e_stack_id stack_id)
{
	t_item	*item;
	t_stack	*stack1;
	t_stack	*stack2;

	if (stack_id == A)
	{
		stack1 = stack_provider(A);
		stack2 = stack_provider(B);
	}
	else
	{
		stack1 = stack_provider(B);
		stack2 = stack_provider(A);
	}
	item = stack2->top;
	take_item(item, stack2);
	--(stack2->size);
	put_item(item, stack1);
	++(stack1->size);
	ft_printf("p%c\n", get_stack_id_char(stack_id));
}

void	swap(enum e_stack_id stack_id)
{
	t_item	*item;
	t_stack	*stack;

	if (stack_id == A)
		stack = stack_provider(A);
	else
		stack = stack_provider(B);
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
			stack = stack_provider(A);
			item = stack->top->next;
			take_item(item, stack);
			put_item(item, stack);
		}
	}
	ft_printf("s%c\n", get_stack_id_char(stack_id));
}

void	rotate(enum e_stack_id stack_id)
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
	ft_printf("r%c\n", get_stack_id_char(stack_id));
}

void	reverse_rotate(enum e_stack_id stack_id)
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
	ft_printf("rr%c\n", get_stack_id_char(stack_id));
}
