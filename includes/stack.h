/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 19:48:47 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "push_swap.h"

enum e_stack_id
{
	A,
	B,
	S,
	R,
	STACK_ID_MAX
};

typedef struct s_item
{
	int				nb;
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