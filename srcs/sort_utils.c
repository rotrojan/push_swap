/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 19:50:52 by bigo             ###   ########.fr       */
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

int	get_mini(
		enum e_stack_id stack_id, void (**shortest_action)(enum e_stack_id))
{
	t_stack			*stack;
	unsigned int	count;
	t_item			*current;
	int				mini;

	stack = stack_provider(stack_id);
	count = stack->size;
	mini = stack->top->nb;
	current = stack->top;
	while (count--)
	{
		if (mini > current->nb)
			mini = current->nb;
		current = current->next;
	}
	if (count > stack->size / 2)
		*shortest_action = &rotate;
	else
		*shortest_action = &reverse_rotate;
	return (mini);
}
