/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:31:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/04 23:37:04 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_both_stack(void)
{
	free_stack(A);
	free_stack(B);
}

static enum e_instruction	free_and_return_instruction(
							enum e_instruction instruction,
							char **instruction_str)
{
	free(*instruction_str);
	*instruction_str = NULL;
	return (instruction);
}

static enum e_instruction	get_next_instruction(void)
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
		while (instruction != WRONG_INSTRUCTION)
		{
			if (ft_strcmp(instruction_str, instruction_array[instruction]) == 0)
				break ;
			++instruction;
		}
		return (free_and_return_instruction(instruction, &instruction_str));
	}
	else if (ret == -1)
		return (free_and_return_instruction(WRONG_INSTRUCTION,
				&instruction_str));
	else
		return (free_and_return_instruction(END_OF_INSTRUCTIONS,
				&instruction_str));
}

static t_error	exec_instructions(void)
{
	enum e_instruction	instruction;
	static	void		(*operations_array[])(void) = {
		&push_a, &push_b,
		&swap_a, &swap_b, &swap_s,
		&rotate_a, &rotate_b, &rotate_r,
		&reverse_rotate_a, &reverse_rotate_b, &reverse_rotate_r
	};

	instruction = get_next_instruction();
	while (instruction != END_OF_INSTRUCTIONS)
	{
		if (instruction == WRONG_INSTRUCTION)
		{
			return (INSTRUCTION_ERROR);
		}
		else if (instruction != END_OF_INSTRUCTIONS)
		{
			operations_array[instruction]();
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
		free_both_stack();
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	error = exec_instructions();
	if (error == INSTRUCTION_ERROR)
	{
		free_both_stack();
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (is_sorted(A) == TRUE && stack_provider(B)->items == NULL)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_both_stack();
	return (EXIT_SUCCESS);
}
