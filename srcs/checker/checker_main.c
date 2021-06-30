/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:31:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/27 22:38:47 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_instruction	get_next_instruction(void)
{
	int		ret;
	char	*instruction_str;
	int		i;

	ret = get_next_line(STDOUT_FILENO, &instruction_str);
	if (ret > 0)
	{
		i = 0;
		while (ft_strcmpinstruction_str, instruction_array[i] != 0)
		{
			++i;
			if (i == INSTRUCTION_ERROR)
		}
		
	}
}

int main(int ac, char **av)
{
	enum e_instruction	instruction;

	instruction = get_next_instruction();
	if (instruction == ERROR)
		exit_error()
		
}
