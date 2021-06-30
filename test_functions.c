#include "push_swap.h"

int	get_median_chunk(t_stack *stack, unsigned int size)
{
	t_item			*current;
	t_item			*to_check;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	to_check = stack->top;
	i = 0;
	while (to_check != NULL && i < size)
	{
		j = i + 1;
		count = 0;
		current = stack->top;
		while (current != NULL && j < size)
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
			ft_printf("yolo\n");
	return (to_check->nb);
}

void	print_stack(enum e_stack_id stack_id)
{
	t_stack	*stack;
	t_item	*current;

	stack = stack_provider(stack_id);
	ft_printf("stack %c\n", get_stack_id_char(stack_id));
	if (stack->top != NULL)
	{
		current = stack->top;
		stack->top->prev->next = NULL;
		while (current != NULL)
		{
			ft_printf("%d\n", current->nb);
			current = current->next;
		}
		stack->top->prev->next = stack->top;
	}
	ft_printf("\n");
}
