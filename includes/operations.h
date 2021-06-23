/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/22 23:34:16 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

/*
** operations_utils.c
*/

void	push(t_stack *stack1, t_stack *stack2);
void	swap(t_stack *stack);

/*
** push.c
*/

void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

/*
** swap.c
*/

void	swap_a(t_stack *stack_a, t_stack *stack_b);
void	swap_b(t_stack *stack_a, t_stack *stack_b);
void	swap_s(t_stack *stack_a, t_stack *stack_b);

/*
** rotate.c
*/

void	rotate_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_r(t_stack *stack_a, t_stack *stack_b);

/*
** reverse_rotate.c
*/

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);

#endif
