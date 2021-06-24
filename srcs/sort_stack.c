/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 20:48:07 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack *stack)
{
	int				median;
	t_item			*current;
	unsigned int	count;

	count = stack->size;
	median = get_median(stack);
	/* stack->top->prev->next = NULL; */
	current = stack->top;
	while (count)
	{
		if (stack->top->nb > median)
			push(B);
		rotate(A);
		--count;
	}
	/* stack->top->prev->next = stack->top; */
}

void	sort_three(void)
{
	int		first;
	int		second;
	int		third;
	t_stack	*stack_a;

	stack_a = stack_provider(A);
	first = stack_a->top->nb;
	second = stack_a->top->next->nb;
	third = stack_a->top->next->next->nb;
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

void	sort_stack(void)
{
	unsigned int	size;
	t_stack			*stack_a;

	stack_a = stack_provider(A);
	size = stack_a->size;
	if (size <= 2)
	{
		if (stack_a->top->nb > stack_a->top->next->nb)
			swap(A);
	}
	else if (size == 3)
	{
		sort_three();
	}
	else
		quick_sort(stack_a);
}
