/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 20:53:45 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "ft_bool.h"
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"
# include "parsing.h"
# include "operations.h"

enum e_instruction
{
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
	INSTRUCTION_ERROR
};

#endif
