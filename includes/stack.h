/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/03 03:46:59 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "push_swap.h"

enum e_stack_id
{
	A,
	B,
	R,
	S,
	STACK_ID_MAX
};

typedef struct s_item
{
	int				nb;
	unsigned int	order;
	struct s_item	*prev;
	struct s_item	*next;
}	t_item;

typedef struct s_stack
{
	struct s_item	*top;
	struct s_item	*items;
	unsigned int	size;
}	t_stack;

#endif
