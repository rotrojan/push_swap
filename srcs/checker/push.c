/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 20:12:25 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker_push(enum e_stack_id stack_id)
{
	t_item	*item;
	t_stack	*stack1;
	t_stack	*stack2;

	if (stack_id == A)
	{
		stack1 = stack_provider(A);
		stack2 = stack_provider(B);
	}
	else
	{
		stack1 = stack_provider(B);
		stack2 = stack_provider(A);
	}
	item = stack2->top;
	take_item(item, stack2);
	--(stack2->size);
	put_item(item, stack1);
	++(stack1->size);
}

void	push_a(void)
{
	checker_push(A);
}

void	push_b(void)
{
	checker_push(B);
}
