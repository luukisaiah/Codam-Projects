/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ps_algorithm.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/20 15:19:42 by lderks         #+#    #+#                */
/*   Updated: 2025/12/09 16:54:21 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int static	bit_count(int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		i++;
		size /= 2;
	}
	return (i);
}

void	small_or_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!sorted_stack(stack_a))
	{
		if ((stack_len(stack_a)) <= 3)
			small_sort(stack_a, stack_b);
		else if ((stack_len(stack_a)) == 4 || (stack_len(stack_a)) == 5)
			five_sort(stack_a, stack_b);
		else
			algorithm(stack_a, stack_b);
	}
}

int	static	find_smallest(t_stack *stack_a, int *i, int *size)
{
	int		smallest_nbr;
	int		pos;
	int		smallest_pos;
	t_node	*current;

	*size = stack_len(stack_a);
	if (*size == 4)
		*i = 1;
	else
		*i = 0;
	smallest_nbr = INT_MAX;
	pos = 0;
	smallest_pos = 0;
	current = stack_a->first_node;
	while (current)
	{
		if (current->value < smallest_nbr)
		{
			smallest_nbr = current->value;
			smallest_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (smallest_pos);
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	smallest_pos;
	int	size;

	smallest_pos = find_smallest(stack_a, &i, &size);
	while (i < 2)
	{
		smallest_pos = find_smallest(stack_a, &i, &size);
		size = stack_len(stack_a);
		if (smallest_pos <= size / 2)
		{
			while (smallest_pos-- > 0)
				rotate(stack_a, stack_b, 'a');
		}
		else
		{
			while (smallest_pos++ < size)
				reverse_rotate(stack_a, stack_b, 'a');
		}
		push(stack_a, stack_b, 'b');
		i++;
	}
	small_sorting(stack_a, stack_b);
	while (stack_b->size > 0)
		push(stack_a, stack_b, 'a');
}

void	algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	number;
	int	size;

	max_bits = bit_count(stack_a->size - 1);
	i = 0;
	while (i < max_bits)
	{
		size = stack_a->size;
		while ((size--) > 0)
		{
			number = stack_a->first_node->index;
			if (((number >> i) & 1) == 1)
				rotate(stack_a, stack_b, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (stack_b->size > 0)
			push (stack_a, stack_b, 'a');
		i++;
	}
}
