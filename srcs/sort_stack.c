/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/30 18:11:42 by rotrojan         ###   ########.fr       */
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

int	get_median_chunk(enum e_stack_id stack_id, unsigned int size)
{
	t_stack			*stack;
	t_item			*current;
	t_item			*to_check;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	stack = stack_provider(stack_id);
	to_check = stack->top;
	i = 0;
	while (i < size)
	{
		j = 0;
		count = 0;
		current = stack->top;
		while (j < size)
		{
			if (current->nb > to_check->nb)
				++count;
			current = current->next;
			++j;
		}
		if (count == stack->size / 2)
			break ;
		to_check = to_check->next;
		++i;
	}
	return (to_check->nb);
}

void	pre_sort(enum e_stack_id stack_id, unsigned int size)
{
	/* t_item	*current; */
	int		median;
	unsigned int		i;
	t_stack	*stack;

	/* current = stack_provider(stack_id)->top; */
	stack = stack_provider(stack_id);
	median = get_median_chunk(stack_id, size);
	ft_printf("median = %d\n", median);
	ft_printf("size = %d\n", size);
	i = 0;
	while (i < size)
	{
		if (stack->top->nb > median)
			push((stack_id + 1) % 2);
		else
			rotate(stack_id);
		++i;
	}
}

static void	quick_sort(void)
{
	t_stack			*stack;
	unsigned int	size;

	stack = stack_provider(A);
	size = stack->size;
	pre_sort(A, size);

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
		quick_sort();
}
