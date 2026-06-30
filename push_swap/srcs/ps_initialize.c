/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ps_initialize.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/20 14:47:49 by lderks         #+#    #+#                */
/*   Updated: 2025/12/09 16:54:04 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	free_array(char **numbers)
{
	int	i;

	i = 0;
	if (!numbers)
		return ;
	while (numbers[i])
	{
		free (numbers[i]);
		i++;
	}
	free (numbers);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*next;

	if (a && a->first_node)
	{
		current = a->first_node;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	if (b && b->first_node)
	{
		current = b->first_node;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	free(a);
	free(b);
}

t_node static	*new_node(int number, t_stack *a, t_stack *b, char **numbers)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_array(numbers);
		free_stacks(a, b);
		ft_putstr_fd("Error:\nnode allocation failed\n", 1);
		exit(EXIT_FAILURE);
	}
	new_node->value = number;
	new_node->next = NULL;
	return (new_node);
}

void	initialize_stack(t_stack *s_a, char **numbers)
{
	int		i;
	t_node	*current;

	if (!numbers || !numbers[0])
	{
		free_array(numbers);
		return ;
	}
	i = 0;
	s_a->first_node = new_node(ft_atoi(numbers[i++]), s_a, NULL, numbers);
	s_a->size++;
	current = s_a->first_node;
	while (numbers[i])
	{
		current->next = new_node(ft_atoi(numbers[i]), s_a, NULL, numbers);
		current = current->next;
		current->next = NULL;
		s_a->size++;
		i++;
	}
	free_array(numbers);
}

void	create_index(t_stack *stack_a)
{
	t_node	*current;
	t_node	*temp;
	int		i;
	int		index;

	i = 0;
	current = stack_a->first_node;
	while (current && i < stack_a->size)
	{
		temp = stack_a->first_node;
		index = 0;
		while (temp)
		{
			if (current->value > temp->value)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}
