/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/23 00:09:38 by bigo             ###   ########.fr       */
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
void	print_stack(t_stack *stack);

#endif
