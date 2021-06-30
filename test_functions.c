#include "push_swap.h"

int	get_median_chunk(enum e_stack_id stack_id, unsigned int size)
{
	t_stack			*stack;
	t_item			*current;
	t_item			*to_check;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	stack = stack_provider(stack_id);
	to_check = stack->top;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		count = 0;
		current = stack->top;
		while (j < size)
		{
			if (current->nb > to_check->nb)
				++count;
			current = current->next;
			++j;
		}
		if (count == stack->size / 2)
			break ;
		to_check = to_check->next;
		++i;
	}
	return (to_check->nb);
}

void	print_stack(enum e_stack_id stack_id)
{
	t_stack	*stack;
	t_item	*current;
	int		stop_flag;

	stack = stack_provider(stack_id);
	ft_printf("stack %c\n", get_stack_id_char(stack_id));
	if (stack->top != NULL)
	{
		current = stack->top;
		stop_flag = 0;
		while (stop_flag == 0)
		{
			ft_printf("%d\n", current->nb);
			current = current->next;
			if (current == stack->top)
				stop_flag = 1;
		}
	}
	ft_printf("\n");
}
