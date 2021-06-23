/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 02:56:24 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	take_item(t_item *item, t_stack *stack)
{
	t_item	*prev;
	t_item	*next;

	if (item != NULL)
	{
		if (stack->items == stack->items->next)
		{
			stack->items = NULL;
			stack->top = NULL;
		}
		else
		{
			prev = item->prev;
			next = item->next;
			prev->next = next;
			next->prev = prev;
			if (item == stack->top)
			{
				stack->items = next;
				stack->top = next;
			}
		}
		item->next = NULL;
		item->prev = NULL;
	}
}

static void	put_item(t_item *item, t_stack *stack)
{
	if (item != NULL)
	{
		if (stack->items == NULL)
		{
			item->next = item;
			item->prev = item;
		}
		else
		{
			stack->items->prev->next = item;
			item->prev = stack->items->prev;
			stack->top->prev = item;
			item->next = stack->top;
		}
		stack->items = item;
		stack->top = stack->items;
	}
}

void	push(t_stack *stack1, t_stack *stack2)
{
	t_item	*item;

	item = stack2->top;
	take_item(item, stack2);
	put_item(item, stack1);
}

void	swap(t_stack *stack)
{
	t_item	*item;

	if (stack->items != NULL)
	{
		item = stack->top->next;
		take_item(item, stack);
		put_item(item, stack);
	}	
}
