/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 22:32:29 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_bool.h"
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"
# include "parsing.h"
# include "operations.h"

void	sort_stack(void);

/*
** stack_utils.c
*/

t_stack	*stack_provider(enum e_stack_id stack_id);
void	free_stack(t_stack *stack_a);

/*
** sort_utils.c
*/

t_bool	is_sorted(enum e_stack_id stack_id);
t_bool	is_reverse_sorted(enum e_stack_id stack_id);
void	*get_shortest_rotate(enum e_stack_id stack_id, int value);
int		get_mini(enum e_stack_id stack_id);

#endif
