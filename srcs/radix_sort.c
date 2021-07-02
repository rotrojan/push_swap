/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 01:14:14 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	last_rotate( enum e_stack_id stack_id)
{
	void	(*shortest_rotate)(enum e_stack_id);
	int		mini;

	mini = get_mini(stack_id);
	shortest_rotate = get_shortest_rotate(stack_id, mini);
	while (is_sorted(stack_id) == FALSE)
		shortest_rotate(stack_id);
}

void	radix_sort(enum e_stack_id stack_id)
{
	unsigned int	mask;
	unsigned int	size;
	t_bool			flag_is_sorted;

	mask = 0x0001;
	flag_is_sorted = 0;
	size = stack_provider(stack_id)->size;
	while (mask != 0)
	{
		sort_by_bit(mask, size, stack_id);
		while (stack_provider((stack_id + 1) % 2)->items != NULL)
			push(stack_id);
		if (is_circular_sorted(stack_id) == TRUE)
		{
			last_rotate(stack_id);
			break ;
		}
		mask = mask << 1;
	}
}
