/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 17:15:46 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

enum e_instruction
{
	INSTRUCTION_ERROR = -1,
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
	END_OF_INSTRUCTIONS
};

#endif
