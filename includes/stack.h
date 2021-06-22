/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/22 16:20:04 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef enum e_operations
{
	Sa,
	Sb,
	Ss,
	Pa,
	Pb,
	Ra,
	Rb,
	Rr,
	Rra,
	Rrb,
	Rrr
}	t_operations;

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
}	t_stack;

#endif
