/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 22:53:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHUNK_SIZE 15

static void	final_sort(enum e_stack_id stack_id)
{
	unsigned int	size;
	unsigned int	order;
	void			(*shortest_rotate)(enum e_stack_id);

	size = stack_provider((stack_id + 1) % 2)->size;
	order = size - 1;
	while (stack_provider((stack_id + 1) % 2)->top != NULL)
	{
		shortest_rotate = get_shortest_rotate((stack_id + 1) % 2,
				get_maxi((stack_id + 1) % 2));
		while (stack_provider((stack_id + 1) % 2)->top->order
			!= stack_provider((stack_id + 1) % 2)->size - 1)
			shortest_rotate((stack_id + 1) % 2);
		push(stack_id);
	}
}

static void	*get_rotate_for_next_in_range(enum e_stack_id stack_id,
			unsigned int range)
{
	t_item			*current;
	unsigned int	nb_rotate;
	unsigned int	nb_reverse_rotate;

	nb_rotate = 0;
	nb_reverse_rotate = 0;
	current = stack_provider(stack_id)->top;
	while (current->order >= range)
	{
		current = current->next;
		++nb_rotate;
	}
	current = stack_provider(stack_id)->top;
	while (current->order >= range)
	{
		current = current->prev;
		++nb_reverse_rotate;
	}
	if (nb_rotate > nb_reverse_rotate)
		return (&reverse_rotate);
	else
		return (&rotate);
}

void	optimized_insertion_sort(enum e_stack_id stack_id)
{
	unsigned int	range;
	unsigned int	i;
	void			(*shortest_rotate)(enum e_stack_id);

	i = 0;
	range = CHUNK_SIZE;
	while (stack_provider(stack_id)->top != NULL)
	{
		shortest_rotate = get_rotate_for_next_in_range(stack_id, range);
		while (stack_provider(stack_id)->top->order > range)
			shortest_rotate(stack_id);
		push((stack_id + 1) % 2);
		++i;
		if (i == range)
			range += CHUNK_SIZE;
	}
	final_sort(stack_id);
}
