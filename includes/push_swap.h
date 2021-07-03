/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 22:51:38 by rotrojan         ###   ########.fr       */
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

/*
** sort_stack.c
*/

void	sort_stack(enum e_stack_id stack_id);

/*
** radix_sort.c
*/

void	radix_sort(enum e_stack_id stack_id);

/*
** insertion_sort.c
*/

void	optimized_insertion_sort(enum e_stack_id stack_id);

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
int		get_maxi(enum e_stack_id stack_id);

#endif
