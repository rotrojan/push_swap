/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 13:23:45 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(void)
{
	t_stack			*stack[2];
	unsigned int	mask;
	unsigned int	i;
	unsigned int	size;

	mask = 0x0001;
	stack[0] = stack_provider(A);
	stack[1] = stack_provider(B);
	size = stack[0]->size;
	while (mask != 0 && is_sorted(stack[0]) == FALSE)
	{
		i = 0;
		while (i < size)
		{
			if ((mask & stack[0]->top->nb) == 0)
				push(B);
			else
				rotate(A);
			++i;
		}
		while (stack[1]->items != NULL)
			push(A);
		mask = mask << 1;
	}
	i = 0;
	while (i < size)
	{
		if ((mask & stack[0]->top->nb) == 1)
			push(B);
		else
			rotate(A);
		++i;
	}
	while (stack[1]->items != NULL)
		push(A);
}

void	sort_stack(void)
{
	unsigned int	size;
	t_stack			*stack_a;

	stack_a = stack_provider(A);
	size = stack_a->size;
	if (is_sorted(stack_a) == TRUE)
		return ;
	if (size <= 2)
		swap(A);
	else if (size == 3)
		sort_three(A);
	else
		radix_sort();
}
