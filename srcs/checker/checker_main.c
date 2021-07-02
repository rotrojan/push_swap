/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:31:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/02 17:53:41 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_instruction	get_next_instruction(void)
{
	int		ret;
	char	*instruction_str;
	int		i;
	char	*instruction_array[] = { "pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	instruction_str = NULL;
	ret = get_next_line(STDOUT_FILENO, &instruction_str);
	if (ret > 0)
	{
		i = 0;
		while (ft_strcmp(instruction_str, instruction_array[i]) != 0)
		{
			++i;
			if (i == INSTRUCTION_ERROR)
				return (INSTRUCTION_ERROR);
		}
		free(instruction_str);
		instruction_str = NULL;
	}
	else if (ret == -1)
		return (INSTRUCTION_ERROR);
	return (END_OF_INSTRUCTIONS);
}

void	exec_instruction(enum e_instruction instruction)
{
	enum e_stack_id	param;
	static void (*operations_array[])(enum e_stack_id) = {
		&push, &push,
		&swap, &swap, &swap,
		&rotate, &rotate, &rotate,
		&reverse_rotate, &reverse_rotate, &reverse_rotate
	};

	if (instruction == PUSH_A || instruction == SWAP_A	\
		|| instruction == ROTATE_A || instruction == REVERSE_ROTATE_A)
		param = A;
	else if (instruction == PUSH_B || instruction == SWAP_B	\
		|| instruction == ROTATE_B || instruction == REVERSE_ROTATE_B)
		param = B;
	else if (instruction == ROTATE_R || instruction == REVERSE_ROTATE_R)
		param = R;
	else if (instruction == SWAP_S)
		param = S;
	else
		return ;
	operations_array[instruction](param);
}

int	main(int ac, char **av)
{
	enum e_instruction	instruction;
	t_error			error;

	if (ac < 2)
		return (EXIT_SUCCESS);
	error = parse_args(av);
	instruction = get_next_instruction();
	while (instruction != END_OF_INSTRUCTIONS)
	{
		instruction = get_next_instruction();
		if (instruction == INSTRUCTION_ERROR)
		{
			free_stack(A);
			free_stack(B);
			ft_putendl_fd("Error", STDERR_FILENO);
		}
		exec_instruction(instruction);
	}
	if (is_sorted(A) == TRUE && stack_provider(B)->items == NULL)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_stack(A);
	free_stack(B);
	return (EXIT_SUCCESS);
}
