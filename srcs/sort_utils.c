/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 19:12:05 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	get_stack_size(t_stack *stack) */
/* { */
	/* unsigned int		size; */
	/* t_item				*current; */

	/* if (stack->items == NULL) */
		/* return (0); */
	/* else */
	/* { */
		/* size = 1; */
		/* current = stack->items->next; */
		/* while (current != stack->top) */
		/* { */
			/* ++size; */
			/* current = current->next; */
		/* } */
		/* return (size); */
	/* } */
/* } */

int	get_median(t_stack *stack)
{
	t_item			*current;
	t_item			*to_check;
	unsigned int	count;

	to_check = stack->top;
	stack->top->prev->next = NULL;
	while (to_check != NULL)
	{
		count = 0;
		current = stack->top;
		while (current != NULL)
		{
			if (current->nb > to_check->nb)
				++count;
			current = current->next;
		}
		if (count == stack->size / 2)
			break ;
		to_check = to_check->next;
	}
	stack->top->prev->next = stack->top;
	return (to_check->nb);
}
