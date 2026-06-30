/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ps_push.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/14 13:17:38 by lderks         #+#    #+#                */
/*   Updated: 2025/04/11 18:21:33 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void static	push_first_node(t_stack *recieve_s, t_stack *give_s)
{
	t_node	*temp;

	temp = recieve_s->first_node;
	recieve_s->first_node = give_s->first_node;
	give_s->first_node = give_s->first_node->next;
	recieve_s->first_node->next = temp;
	recieve_s->size++;
	give_s->size--;
}

void	push(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		push_first_node(a, b);
		ft_putendl_fd("pa", 1);
	}
	if (c == 'b')
	{
		push_first_node(b, a);
		ft_putendl_fd("pb", 1);
	}
}
