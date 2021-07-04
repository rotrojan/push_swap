/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/04 21:01:11 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_next_mini(enum e_stack_id stack_id, int mini)
{
	unsigned int	stop_flag;
	t_item			*current;
	int				next_mini;

	current = stack_provider(stack_id)->top;
	next_mini = INT_MAX;
	stop_flag = FALSE;
	while (stop_flag == FALSE)
	{
		if (current->nb < next_mini && current->nb > mini)
			next_mini = current->nb;
		current = current->next;
		if (current == stack_provider(stack_id)->top)
			stop_flag = TRUE;
	}
	return (next_mini);
}

int	get_maxi(enum e_stack_id stack_id)
{
	t_item			*current;
	unsigned int	size;

	current = stack_provider(stack_id)->top;
	size = stack_provider(stack_id)->size;
	while (current->order != size - 1)
		current = current->next;
	return (current->nb);
}
