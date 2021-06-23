/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:46:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/22 23:21:03 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "push_swap.h"

# define DUPLICATE_ERROR_STR "The arguments should not include duplicates"
# define NON_DIGIT_ERROR_STR "The arguments should only be integers"
# define OUT_OF_RANGE_ERROR_STR "Some argument(s) exceed the range of integers"
# define MALLOC_FAILURE_ERROR_STR "Malloc failure"

typedef enum e_error
{
	No_error,
	Duplicate_error,
	Non_digit_error,
	Out_of_range_error,
	Malloc_failure_error,
	Error_max
}	t_error;

t_error	parse_args(char **av, t_stack *stack_a);

#endif
