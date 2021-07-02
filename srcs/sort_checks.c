/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:52:56 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 01:13:09 by bigo             ###   ########.fr       */
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

t_bool	is_circular_sorted(enum e_stack_id stack_id)
{
	t_stack			*stack;
	t_item			*current;
	t_bool			stop_flag;
	int				mini;

	stack = stack_provider(stack_id);
	mini = get_mini(stack_id);
	current = stack->top;
	while (current->nb != mini)
		current = current->next;
	stop_flag = FALSE;
	while (stop_flag == FALSE)
	{
		if (current->nb > current->next->nb)
			return (FALSE);
		current = current->next;
		if (current->next->nb == mini)
			stop_flag = TRUE;
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
