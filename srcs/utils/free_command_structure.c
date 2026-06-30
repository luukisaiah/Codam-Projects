/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:43:38 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:26:58 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(t_minishell *shell, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		safe_free(shell, (void **)&array[i]);
		array[i] = NULL;
		i++;
	}
	safe_free(shell, (void **)&array);
}

void	free_redir_list(t_minishell *shell, t_redir *redir_list) //
{
	t_redir	*current;
	t_redir	*next;

	current = redir_list;
	while (current)
	{
		next = current->next;
		if (current->file)
			safe_free(shell, (void **)&current->file);
		if (current)
			safe_free(shell, (void **)&current);
		current = next;
	}
	redir_list = NULL;
}

void	free_command_structure(t_minishell *shell, t_command *commands)
{
	t_command	*current;
	t_command	*next;

	if (!commands)
		return ;
	current = commands;
	while (current)
	{
		next = current->next;
		close_command_fds(current);
		if (current->args)
			free_array(shell, current->args);
		if (current->redir_list)
			free_redir_list(shell, current->redir_list);
		safe_free(shell, (void **)&current);
		current = next;
	}
}
