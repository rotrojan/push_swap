/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 23:13:44 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(enum e_stack_id stack_id)
{
	t_stack	*stack;
	t_item	*current;
	int		stop_flag;

	stack = stack_provider(stack_id);
	ft_printf("stack %c\n", get_stack_id_char(stack_id));
	if (stack->top != NULL)
	{
		current = stack->top;
		stop_flag = 0;
		while (stop_flag == 0)
		{
			ft_printf("%d\n", current->nb);
			current = current->next;
			if (current == stack->top)
				stop_flag = 1;
		}
	}
	ft_printf("\n");
}
