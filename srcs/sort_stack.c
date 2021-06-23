/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 03:03:02 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void print_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Stack A\n");
	print_stack(stack_a);
	ft_printf("\n");

	ft_printf("Stack B\n");
	print_stack(stack_b);
	ft_printf("\n");
}
*/

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_r(stack_a, stack_b);
}
