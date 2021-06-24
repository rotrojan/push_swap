/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 19:52:52 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

/*
** operations_utils.c
*/

void	take_item(t_item *item, t_stack *stack);
void	put_item(t_item *item, t_stack *stack);
char	get_stack_id_char(enum e_stack_id stack_id);

/*
** operations.c
*/

void	push(enum e_stack_id stack_id);
void	swap(enum e_stack_id stack_id);
void	rotate(enum e_stack_id stack_id);
void	reverse_rotate(enum e_stack_id stack_id);

#endif
