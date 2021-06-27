/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 20:01:40 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(enum e_stack_id stack_id)
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

static void	sort_five(enum e_stack_id stack_id)
{
	t_stack	*stack;
	void	(*shortest_rotate)(enum e_stack_id);
	int		mini;

	shortest_rotate = NULL;
	stack = stack_provider(stack_id);
	while (stack->size > 3)
	{
		mini = get_mini(stack_id, &shortest_rotate);
		while (stack->top->nb != mini)
			shortest_rotate(stack_id);
		push((stack_id + 1) % 2);
	}
	sort_three(stack_id);
	while (stack_provider((stack_id + 1) % 2)->top != NULL)
		push(stack_id);
}

static void	sort_by_bit(
	unsigned int mask, unsigned int size, enum e_stack_id stack_id)
{
	unsigned int	i;
	t_stack			*stack;

	i = 0;
	stack = stack_provider(stack_id);
	while (i < size)
	{
		if ((mask & stack->top->nb) == 0)
			push((stack_id + 1) % 2);
		else
			rotate(stack_id);
		++i;
	}
}

static void	radix_sort(enum e_stack_id stack_id)
{
	unsigned int	mask;
	unsigned int	size;
	int				flag;

	mask = 0x0001;
	flag = 0;
	size = stack_provider(stack_id)->size;
	while (mask != 0 && is_sorted(stack_id) == FALSE)
	{
		sort_by_bit(mask, size, stack_id);
		if (is_sorted(stack_id) == TRUE
			&& is_reverse_sorted((stack_id + 1 ) % 2) == TRUE)
			flag = 1;
		while (stack_provider((stack_id + 1) % 2)->items != NULL)
			push(A);
		if (flag == 1)
		{
			while (is_sorted(stack_id) == FALSE)
				rotate(A);
			break ;
		}
		mask = mask << 1;
	}
}

void	sort_stack(void)
{
	unsigned int	size;

	size = stack_provider(A)->size;
	if (is_sorted(A) == TRUE)
		return ;
	else if (size == 2)
		swap(A);
	else if (size == 3)
		sort_three(A);
	else if (size <= 5)
		sort_five(A);
	else
		radix_sort(A);
}
