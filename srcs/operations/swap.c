/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 02:47:16 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
