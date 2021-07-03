/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 03:46:38 by bigo             ###   ########.fr       */
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

	stack = stack_provider(stack_id);
	while (stack->size > 3)
	{
		mini = get_mini(stack_id);
		shortest_rotate = get_shortest_rotate(stack_id, mini);
		while (stack->top->nb != mini)
			shortest_rotate(stack_id);
		push((stack_id + 1) % 2);
	}
	sort_three(stack_id);
	while (stack_provider((stack_id + 1) % 2)->top != NULL)
		push(stack_id);
}

void	sort_stack(enum e_stack_id stack_id)
{
	unsigned int	size;

	size = stack_provider(stack_id)->size;
	if (is_sorted(stack_id) == TRUE)
		return ;
	else if (size == 2)
		swap(A);
	else if (size == 3)
		sort_three(A);
	else if (size <= 5)
		sort_five(A);
	else
		sort();
}
