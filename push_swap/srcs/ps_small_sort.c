/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ps_small_sort.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/10 19:16:53 by lderks         #+#    #+#                */
/*   Updated: 2025/04/15 20:04:31 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	concat_args(int argc, char **argv, char **s, size_t len)
{
	int	i;

	(*s)[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(*s, argv[i], len);
		if (i < argc - 1)
			ft_strlcat(*s, " ", len);
		i++;
	}
}

int	sorted_stack(t_stack *stack_a)
{
	t_node	*current;

	if (!stack_a || !stack_a->first_node)
		return (1);
	current = stack_a->first_node;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_len(t_stack *stack_a)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!stack_a || !stack_a->first_node)
		return (0);
	current = stack_a->first_node;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	get_value_pos(t_stack *stack_a, int position)
{
	t_node	*current;
	int		i;

	if (!stack_a || stack_a->size <= 0 || !stack_a->first_node)
		return (1);
	current = stack_a->first_node;
	i = 0;
	while (current && i < position)
	{
		current = current->next;
		i++;
	}
	if (current)
		return (current->value);
	else
		return (0);
}

void	small_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;
	int	c;

	a = get_value_pos(stack_a, 0);
	b = get_value_pos(stack_a, 1);
	c = get_value_pos(stack_a, 2);
	if (a > b && b > c && a > c)
	{
		swap(stack_a, stack_b, 'a');
		reverse_rotate(stack_a, stack_b, 'a');
	}
	else if (a > c && c > b && a > c)
		rotate(stack_a, stack_b, 'a');
	else if (b > c && c > a && b > a)
	{
		swap(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	else if (b > a && a > c && b > c)
		reverse_rotate(stack_a, stack_b, 'a');
	else if (c > a && a > b && c > b)
		swap(stack_a, stack_b, 'a');
}
