/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ps_swap.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/11 13:51:24 by lderks         #+#    #+#                */
/*   Updated: 2025/04/11 18:22:22 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;

	if (!stack->first_node || !stack->first_node->next)
		return ;
	temp = stack->first_node->value;
	stack->first_node->value = stack->first_node->next->value;
	stack->first_node->next->value = temp;
}

void	swap(t_stack *a_stack, t_stack *b_stack, char c)
{
	if (c == 'a')
	{
		swap_stack(a_stack);
		ft_putendl_fd("sa", 1);
	}
	if (c == 'b')
	{
		swap_stack(b_stack);
		ft_putendl_fd("sb", 1);
	}
	if (c == 'x')
	{
		swap_stack(a_stack);
		swap_stack(b_stack);
		ft_putendl_fd("ss", 1);
	}
}
