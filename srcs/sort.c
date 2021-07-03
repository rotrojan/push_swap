/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:22:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/29 00:25:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotation(unsigned int nb_rotations, enum e_stack_id stack_id,
		void (*rotate_function)(enum e_stack_id))
{
	unsigned int	i;

	i = 0;
	while (i < nb_rotations)
	{
		rotate_function(stack_id);
		++i;
	}
}

void	execute_rotations(unsigned int nb_r[3], unsigned int nb_rr[3])
{
	execute_rotation(nb_r[A], A, &rotate);
	execute_rotation(nb_r[B], B, &rotate);
	execute_rotation(nb_r[R], R, &rotate);
	execute_rotation(nb_rr[A], A, &reverse_rotate);
	execute_rotation(nb_rr[B], B, &reverse_rotate);
	execute_rotation(nb_rr[R], R, &reverse_rotate);
}

void	print_rotations(unsigned int nb_r[3], unsigned int nb_rr[3])
{
	ft_printf("ra : %d\n", nb_r[A]);
	ft_printf("rra: %d\n", nb_rr[A]);
	ft_printf("rb : %d\n", nb_r[B]);
	ft_printf("rrb: %d\n", nb_rr[B]);
	ft_printf("rr : %d\n", nb_r[R]);
	ft_printf("rrr: %d\n\n", nb_rr[R]);
}

int		get_next_number(int nb)
{
	t_item	*current;

	current = stack_provider(B)->top;
	while (nb > current->prev->nb && nb < current->nb)
	{
		current = current->next;
	}
	return (current->nb);
}

void	get_nb_rotate_b(int nb, unsigned int nb_r[3], unsigned int nb_rr[3])
{
	unsigned int	size;
	t_item			*current;
	int				next_number;

	size = stack_provider(B)->size;
	current = stack_provider(B)->items;
	if (nb < get_mini(B))
		return ;
	next_number = get_next_number(nb);
	if (get_shortest_rotate(B, next_number) == &rotate)
	{
		while (current->nb != next_number)
		{
			++nb_r[B];
			current = current->next;
		}
	}
	else
	{
		while (current->nb != next_number)
		{
			++nb_rr[B];
			current = current->prev;
		}
	}
}

void	get_nb_rotate_a(int nb, unsigned int nb_r[3], unsigned int nb_rr[3])
{
	t_item	*current;

	current = stack_provider(A)->top;
	if (nb == current->nb)
		return ;
	if (get_shortest_rotate(A, nb) == &rotate)
	{
		while (current->nb != nb)
		{
			++nb_r[A];
			current = current->next;
		}
	}
	else if (get_shortest_rotate(A, nb) == &reverse_rotate)
	{
		while (current->nb != nb)
		{
			++nb_rr[A];
			current = current->prev;
		}
	}
}

int	get_nb_rotations(int nb, unsigned int nb_r[3], unsigned int nb_rr[3])
{
	get_nb_rotate_a(nb, nb_r, nb_rr);
	get_nb_rotate_b(nb, nb_r, nb_rr);
	while (nb_r[A] > 0 && nb_r[B] > 0)
	{
		--nb_r[A];
		--nb_r[B];
		++nb_r[R];
	}
	while (nb_rr[A] > 0 && nb_rr[B] > 0)
	{
		--nb_rr[A];
		--nb_rr[B];
		++nb_rr[R];
	}
	return (nb_r[A] + nb_r[B] + nb_r[R] + nb_rr[A] + nb_rr[B] + nb_rr[R]);
}

void	get_quickest_rotations(unsigned int nb_r_mini[3],
		unsigned int nb_rr_mini[3])
{
	unsigned int	nb_rotations;
	unsigned int	nb_rotations_mini;
	unsigned int	nb_r[3];
	unsigned int	nb_rr[3];
	t_item			*current;
	unsigned int	i;

	i = 0;
	nb_rotations_mini = UINT_MAX;
	current = stack_provider(A)->top;
	while (i < stack_provider(A)->size)
	{
		ft_bzero(&nb_r, sizeof(nb_r));
		ft_bzero(&nb_rr, sizeof(nb_rr));
		nb_rotations = get_nb_rotations(current->nb, nb_r, nb_rr);
		if (nb_rotations < nb_rotations_mini)
		{
			nb_rotations_mini = nb_rotations;
			nb_r_mini[A] = nb_r[A];
			nb_r_mini[B] = nb_r[B];
			nb_r_mini[R] = nb_r[R];
			nb_rr_mini[A] = nb_rr[A];
			nb_rr_mini[B] = nb_rr[B];
			nb_rr_mini[R] = nb_rr[R];
		}
		current = current->next;
		++i;
	}
}

void	sort(void)
{
	unsigned int	nb_r_mini[3];
	unsigned int	nb_rr_mini[3];

	push(B);
	while (stack_provider(A)->top != NULL)
	{
		ft_bzero(&nb_r_mini, sizeof(nb_r_mini));
		ft_bzero(&nb_rr_mini, sizeof(nb_rr_mini));
		get_quickest_rotations(nb_r_mini, nb_rr_mini);
		execute_rotations(nb_r_mini, nb_rr_mini);
		push(B);
	}
	while (stack_provider(B)->top != NULL)
	{
		push(A);
	}
}
