/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:46:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 20:39:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "push_swap.h"

#define DUPLICATE_ERROR_STR "The arguments should not include duplicates."
#define NON_DIGIT_ERROR_STR "The arguments should only be integers."
#define OUT_OF_RANGE_ERROR_STR "Some argument(s) exceed the range of integers."

typedef enum e_error
{
	NO_ERROR,
	DUPLICATE_ERROR,
	NON_DIGIT_ERROR,
	OUT_OF_RANGE_ERROR
}	t_error;

t_error	parsing(char **av, t_stack *stack_a);

#endif
