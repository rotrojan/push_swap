/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:46:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 23:06:45 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "push_swap.h"

typedef enum e_error
{
	NO_ERROR,
	DUPLICATE_ERROR,
	NON_DIGIT_ERROR,
	OUT_OF_RANGE_ERROR,
	MALLOC_FAILURE_ERROR,
	INSTRUCTION_ERROR,
}	t_error;

t_error	parse_args(char **av);

#endif
