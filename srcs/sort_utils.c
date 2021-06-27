/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 13:06:18 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_stack *stack)
{
	t_item			*current;
	unsigned int	size;
	unsigned int	i;

	current = stack->top;
	i = 0;
	size = stack->size;
	while (i < size)
	{
		if (current->nb > current->next->nb && current->next != stack->top)
			return (FALSE);
		current = current->next;
		++i;
	}
	return (TRUE);
}

void	sort_three(enum e_stack_id stack_id)
{
	int		first;
	int		second;
	int		third;
	t_stack	*stack;

	stack = stack_provider(stack_id);
	first = stack->top->nb;
	second = stack->top->next->nb;
	third = stack->top->next->next->nb;
	if (first > second && first < third && second < third)
		swap(A);
	else if (first > second && first > third && second > third)
	{
		swap(A);
		reverse_rotate(A);
	}
	else if (first > second && first > third && second < third)
		rotate(A);
	else if (first < second && first < third && second > third)
	{
		swap(A);
		rotate(A);
	}
	else if (first < second && first > third && second > third)
		reverse_rotate(A);
}
