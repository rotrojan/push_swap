/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/24 20:45:24 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_error	check_arg(char const *arg)
{
	char const	*ptr;

	ptr = arg;
	if (ft_isspace(*ptr) == TRUE)
		while (ft_isspace(*ptr) == TRUE)
			++ptr;
	if (*ptr == '+' || *ptr == '-')
		++ptr;
	if (ft_isdigit(*ptr) == FALSE)
		return (NON_DIGIT_ERROR);
	while (ft_isdigit(*ptr) == TRUE)
		++ptr;
	if (*ptr != '\0')
		return (NON_DIGIT_ERROR);
	if (ft_atoi(arg) != ft_atoll(arg))
		return (OUT_OF_RANGE_ERROR);
	return (NO_ERROR);
}

static t_bool	check_duplicates(t_stack const *stack_a)
{
	t_item	*current;
	t_item	*to_check;

	to_check = stack_a->top->prev;
	current = to_check->prev;
	while (to_check != stack_a->top)
	{
		while (current != stack_a->top->prev)
		{
			if (current->nb == to_check->nb)
				return (FALSE);
			current = current->prev;
		}
		to_check = to_check->prev;
		current = to_check->prev;
	}
	return (TRUE);
}

t_bool	add_arg_to_stack_a(char const *arg, t_stack *stack_a)
{
	t_item	*new_item;

	new_item = NULL;
	new_item = malloc(sizeof(*new_item));
	if (new_item == NULL)
		return (FALSE);
	new_item->nb = ft_atoi(arg);
	if (stack_a->items == NULL)
	{
		stack_a->items = new_item;
		stack_a->top = new_item;
		stack_a->items->next = new_item;
		stack_a->items->prev = new_item;
	}
	else
	{
		stack_a->top->prev->next = new_item;
		new_item->prev = stack_a->top->prev;
		stack_a->top->prev = new_item;
		new_item->next = stack_a->top;
	}
	++(stack_provider(A)->size);
	return (TRUE);
}

t_error	parse_args(char **av)
{
	t_error	error;
	t_stack	*stack_a;
	int		i;

	i = 1;
	error = NO_ERROR;
	stack_a = stack_provider(A);
	while (av[i])
	{
		error = check_arg(av[i]);
		if (error != NO_ERROR)
			return (error);
		if (add_arg_to_stack_a(av[i], stack_a) == FALSE)
			return (MALLOC_FAILURE_ERROR);
		i++;
	}
	if (check_duplicates(stack_a) == FALSE)
		error = DUPLICATE_ERROR;
	return (error);
}
