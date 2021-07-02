/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 23:06:12 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

enum e_instruction
{
	END_OF_INSTRUCTIONS = -1,
	PUSH_A,
	PUSH_B,
	SWAP_A,
	SWAP_B,
	SWAP_S,
	ROTATE_A,
	ROTATE_B,
	ROTATE_R,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_R,
	WRONG_INSTRUCTION
};

void	push_a(void);
void	push_b(void);
void	swap_a(void);
void	swap_b(void);
void	swap_s(void);
void	rotate_a(void);
void	rotate_b(void);
void	rotate_r(void);
void	reverse_rotate_a(void);
void	reverse_rotate_b(void);
void	reverse_rotate_r(void);

#endif
