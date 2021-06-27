/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/26 16:21:11 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	get_stack_id_char(enum e_stack_id stack_id)
{
	if (stack_id == A)
		return ('a');
	else if (stack_id == B)
		return ('b');
	else if (stack_id == S)
		return ('s');
	else
		return ('r');
}

void	take_item(t_item *item, t_stack *stack)
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

void	put_item(t_item *item, t_stack *stack)
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
