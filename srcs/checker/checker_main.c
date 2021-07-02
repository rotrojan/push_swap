/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:31:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 23:12:24 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_instruction	get_next_instruction(void)
{
	int					ret;
	char				*instruction_str;
	enum e_instruction	instruction;
	static char			*instruction_array[] = {"pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	instruction_str = NULL;
	ret = get_next_line(STDIN_FILENO, &instruction_str);
	if (ret > 0)
	{
		instruction = 0;
		while (instruction != INSTRUCTION_ERROR)
		{
			if (ft_strcmp(instruction_str, instruction_array[instruction]) == 0)
				break ;
			++instruction;
		}
		free(instruction_str);
		instruction_str = NULL;
		return (instruction);
	}
	else if (ret == -1)
		return (WRONG_INSTRUCTION);
	else
		return (END_OF_INSTRUCTIONS);
}

void	exec_instruction(enum e_instruction instruction)
{
	static	void	(*operations_array[])(void) = {
		&push_a, &push_b,
		&swap_a, &swap_b, &swap_s,
		&rotate_a, &rotate_b, &rotate_r,
		&reverse_rotate_a, &reverse_rotate_b, &reverse_rotate_r
	};

	operations_array[instruction]();
}

t_error	exec_next_instruction(void)
{
	enum e_instruction	instruction;

	instruction = get_next_instruction();
	while (instruction != END_OF_INSTRUCTIONS)
	{
		if (instruction == WRONG_INSTRUCTION)
			return (INSTRUCTION_ERROR);
		else if (instruction == END_OF_INSTRUCTIONS)
		{
			free_stack(A);
			free_stack(B);
		}
		else
		{
			exec_instruction(instruction);
			instruction = get_next_instruction();
		}
	}
	return (NO_ERROR);
}

int	main(int ac, char **av)
{
	t_error			error;

	if (ac < 2)
		return (EXIT_SUCCESS);
	error = parse_args(av);
	if (error != NO_ERROR)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	error = exec_next_instruction();
	if (error == INSTRUCTION_ERROR)
	{
		free_stack(A);
		free_stack(B);
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (is_sorted(A) == TRUE && stack_provider(B)->items == NULL)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_stack(A);
	free_stack(B);
	return (EXIT_SUCCESS);
}
