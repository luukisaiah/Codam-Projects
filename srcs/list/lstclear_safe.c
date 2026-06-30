/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstclear_safe.c                                     :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 12:41:58 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 15:19:47 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_in_freelist(t_minishell *shell, void *ptr)
{
	t_list	*cur;

	if (!shell || !ptr)
		return (0);
	cur = shell->freelist;
	while (cur)
	{
		if (cur->content == ptr)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	lstclear_safe(t_minishell *shell, t_list **lst,
		void (*func)(t_minishell *shell, void *content))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		if (func)
			func(shell, current->content);
		if (is_in_freelist(shell, current))
			safe_free(shell, (void **)&current);
		else
		{
			free(current);
			current = NULL;
		}
		current = next;
	}
	*lst = NULL;
}
