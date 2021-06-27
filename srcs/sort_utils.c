/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 22:36:26 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(enum e_stack_id stack_id)
{
	t_stack			*stack;
	t_item			*current;
	unsigned int	size;
	unsigned int	i;

	stack = stack_provider(stack_id);
	current = stack->top;
	size = stack->size;
	i = 0;
	while (i < size)
	{
		if (current->nb > current->next->nb && current->next != stack->top)
			return (FALSE);
		current = current->next;
		++i;
	}
	return (TRUE);
}

t_bool	is_reverse_sorted(enum e_stack_id stack_id)
{
	t_stack			*stack;
	t_item			*current;
	unsigned int	size;
	unsigned int	i;

	stack = stack_provider(stack_id);
	current = stack->top;
	size = stack->size;
	i = 0;
	while (i < size)
	{
		if (current->nb < current->next->nb && current->next != stack->top)
			return (FALSE);
		current = current->next;
		++i;
	}
	return (TRUE);
}

void	*get_shortest_rotate(enum e_stack_id stack_id, int value)
{
	t_stack			*stack;
	unsigned int	rotate_index;
	unsigned int	reverse_rotate_index;
	t_item			*current;

	stack = stack_provider(stack_id);
	rotate_index = 0;
	reverse_rotate_index = 0;
	current = stack->top;
	while (current->nb != value)
	{
		current = current->next;
		++rotate_index;
	}
	current = stack->top;
	while (current->nb != value)
	{
		current = current->prev;
		++reverse_rotate_index;
	}
	if (rotate_index < reverse_rotate_index)
		return (&rotate);
	else
		return (&reverse_rotate);
}

int	get_mini(enum e_stack_id stack_id)
{
	t_stack			*stack;
	unsigned int	i;
	unsigned int	size;
	t_item			*current;
	int				mini;

	stack = stack_provider(stack_id);
	mini = stack->top->nb;
	current = stack->top;
	size = stack->size;
	i = 0;
	while (i < size)
	{
		if (mini > current->nb)
			mini = current->nb;
		current = current->next;
		++i;
	}
	return (mini);
}
