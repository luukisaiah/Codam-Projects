/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ps_rotate.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/14 13:48:33 by lderks         #+#    #+#                */
/*   Updated: 2025/04/12 14:16:29 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void static	rotate_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*current;

	if (stack->size < 2)
		return ;
	temp = stack->first_node;
	current = stack->first_node;
	stack->first_node = stack->first_node->next;
	while (current->next)
		current = current->next;
	temp->next = NULL;
	current->next = temp;
}

void static	reverse_rotate_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*new_last;

	if (stack->size < 2)
		return ;
	current = stack->first_node;
	while (current->next)
	{
		new_last = current;
		current = current->next;
	}
	new_last->next = NULL;
	current->next = stack->first_node;
	stack->first_node = current;
}

void	rotate(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		rotate_stack(a);
		ft_putendl_fd("ra", 1);
	}
	if (c == 'b')
	{
		rotate_stack(b);
		ft_putendl_fd("rb", 1);
	}
	if (c == 'x')
	{
		rotate_stack(a);
		rotate_stack(b);
		ft_putendl_fd("rr", 1);
	}
}

void	reverse_rotate(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		reverse_rotate_stack(a);
		ft_putendl_fd("rra", 1);
	}
	if (c == 'b')
	{
		reverse_rotate_stack(b);
		ft_putendl_fd("rrb", 1);
	}
	if (c == 'x')
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
		ft_putendl_fd("rrr", 1);
	}
}
