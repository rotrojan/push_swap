/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 03:47:27 by bigo             ###   ########.fr       */
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

void	sort_stack(enum e_stack_id stack_id);
void	radix_sort(enum e_stack_id stack_id);

/*
** stack_utils.c
*/

void	sort(void);


/*
** stack_utils.c
*/

t_stack	*stack_provider(enum e_stack_id stack_id);
void	free_stack(enum e_stack_id stack_id);
void	order_stack(enum e_stack_id stack_id);

/*
** sort_checks.c
*/

t_bool	is_sorted(enum e_stack_id stack_id);
t_bool	is_circular_sorted(enum e_stack_id stack_id);
t_bool	is_reverse_sorted(enum e_stack_id stack_id);

/*
** sort_utils.c
*/

void	*get_shortest_rotate(enum e_stack_id stack_id, int value);
int		get_mini(enum e_stack_id stack_id);

#endif
