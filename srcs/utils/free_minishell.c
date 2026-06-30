/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_minishell.c                                    :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 17:03:18 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 19:34:53 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell(t_minishell *shell)
{
	t_list	*freelist;
	t_list	*next;

	if (!shell)
		return ;
	if (!shell->freelist)
		return ;
	freelist = shell->freelist;
	while (freelist)
	{
		next = freelist->next;
		if (freelist->content)
			free(freelist->content);
		if (freelist)
			free(freelist);
		freelist = next;
	}
	shell->freelist = NULL;
}
