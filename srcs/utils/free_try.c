/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:09:02 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/10 20:09:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_shell(t_minishell *shell)
{
	t_env	*env_current;
	t_env	*env_next;

	free_minishell_input(shell);
	env_current = shell->env_list;
	while (env_current)
	{
		env_next = env_current->next;
		if (env_current->name)
			safe_free(shell, (void **)&env_current->name);
		if (env_current->value)
			safe_free(shell, (void **)&env_current->value);
		safe_free(shell, (void **)&env_current);
		env_current = env_next;
	}
	shell->env_list = NULL;
	rl_clear_history();
	free_remaining_in_freelist(shell);
}

void	free_remaining_in_freelist(t_minishell *shell)
{
	t_list	*current;
	t_list	*next;

	current = shell->freelist;
	while (current)
	{
		next = current->next;
		if (current->content)
			free(current->content);
		free(current);
		current = next;
	}
	shell->freelist = NULL;
}
