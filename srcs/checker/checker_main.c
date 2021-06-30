/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:31:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/30 19:10:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_instruction	get_next_instruction(void)
{
	int		ret;
	char	*instruction_str;
	int		i;

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
		return (INSTRUCTIONS_ERROR);
	else
		return (END_OF_INSTRUCTIONS);

void	exec_instruction(enun e_instruction instruction)
{
	static void (*operations_array)[](enum e_stack_id) = {
		&pushi(A),
		&push(B),
		&swap,
		&swap,
		&swap,
		&rotate,
		&rotate,
		&rotate,
		&reverse_rotate,
		&reverse_rotate,
		&reverse_rotate
	};

	
}

int main(int ac, char **av)
{
	enum e_instruction	instruction;
	t_error			error;

	if (ac < 2)
		return (0);
	error = parse_args(av);
	while ()
	instruction = get_next_instruction();
	if (instruction == ERROR)
		exit_error("ERROR");
	exec_instruction()
		
}
