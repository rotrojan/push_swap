/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:45:33 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/22 21:49:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_error	check_arg(char const *arg)
{
	char const	*ptr;

	ptr = arg;
	if (ft_isspace(*ptr) == True)
		while (ft_isspace(*ptr) == True)
			++ptr;
	if (*ptr == '+' || *ptr == '-')
		++ptr;
	if (ft_isdigit(*ptr) == False)
		return (Non_digit_error);
	while (ft_isdigit(*ptr) == True)
		++ptr;
	if (*ptr != '\0')
		return (Non_digit_error);
	if (ft_atoi(arg) != ft_atoll(arg))
		return (Out_of_range_error);
	return (No_error);
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
				return (False);
			current = current->prev;
		}
		to_check = to_check->prev;
		current = to_check->prev;
	}
	return (True);
}

t_bool	add_arg_to_stack_a(char const *arg, t_stack *stack_a)
{
	t_item	*new_item;

	new_item = NULL;
	new_item = malloc(sizeof(*new_item));
	if (new_item == NULL)
		return (False);
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
	return (True);
}

t_error	parse_args(char **av, t_stack *stack_a)
{
	t_error	error;
	int		i;

	i = 1;
	error = No_error;
	while (av[i])
	{
		error = check_arg(av[i]);
		if (error != No_error)
			return (error);
		if (add_arg_to_stack_a(av[i], stack_a) == False)
			return (Malloc_failure_error);
		i++;
	}
	if (check_duplicates(stack_a) == False)
		error = Duplicate_error;
	return (error);
}
