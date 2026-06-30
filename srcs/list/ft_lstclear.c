/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/09 12:43:23 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 13:00:20 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_list **list, void (*func)(void *content))
{
	t_list	*next;

	if (!func || !list)
		return ;
	while (*list)
	{
		if ((*list)->next)
			next = (*list)->next;
		else
			next = NULL;
		func((*list)->content);
		free(*list);
		*list = next;
	}
}
