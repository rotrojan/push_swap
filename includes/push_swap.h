/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 18:54:26 by rotrojan         ###   ########.fr       */
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

void	sort_stack(t_stack *stack_a, t_stack *stack_b);

/*
** sort_utils.c
*/

int		get_stack_size(t_stack *stack);
int		get_median(t_stack *stack);

#endif
