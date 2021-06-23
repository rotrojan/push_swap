/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 19:47:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void print_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Stack A\n");
	print_stack(stack_a);
	ft_printf("\n");

	ft_printf("Stack B\n");
	print_stack(stack_b);
	ft_printf("\n");
}
*/

void	quick_sort(t_stack *stack_a, t_stack *stack_b, unsigned int size)
{
	int				median;
	t_item			*current;

	median = get_median(stack_a);
	/* stack->top->prev->next = NULL; */
	current = stack_a->top;
	while (size)
	{
		if (stack_a->top->nb > median)
			push_b(stack_a, stack_b);
		rotate_a(stack_a, stack_b);
		--size;
	}
	/* stack->top->prev->next = stack->top; */
}

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top->nb;
	second = stack_a->top->next->nb;
	third = stack_a->top->next->next->nb;
	if (first > second && first < third && second < third)
		swap_a(stack_a, stack_b);
	else if (first > second && first > third && second > third)
	{
		swap_a(stack_a, stack_b);
		reverse_rotate_a(stack_a, stack_b);
	}
	else if (first > second && first > third && second < third)
		rotate_a(stack_a, stack_b);
	else if (first < second && first < third && second > third)
	{
		swap_a(stack_a, stack_b);
		rotate_a(stack_a, stack_b);
	}
	else if (first < second && first > third && second > third)
		reverse_rotate_a(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	size;

	size = get_stack_size(stack_a);
	if (size == 2)
	{
		if (stack_a->top->nb > stack_a->top->next->nb)
			swap_a(stack_a, stack_b);
	}
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else
		quick_sort(stack_a, stack_b, size);
}
