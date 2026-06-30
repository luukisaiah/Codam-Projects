/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_remove.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:01:03 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 13:10:13 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env_var(t_minishell *shell, t_env *env_list, char *name)
{
	t_env	*current;
	t_env	*prev;
	t_env	*to_delete;

	current = env_list;
	prev = NULL;
	if (current && ft_strcmp (current->name, name) == 0)
	{
		env_list = current->next;
		free_env_node(shell, current);
		return ;
	}
	current = env_list;
	while (current && current->next)
	{
		if (ft_strcmp(current->next->name, name) == 0)
		{
			to_delete = current->next;
			current->next = to_delete->next;
			free_env_node(shell, to_delete);
			return ;
		}
		current = current->next;
	}
}

void	free_env_node(t_minishell *shell, t_env *node)
{
	if (!node)
		return ;
	if (node->name)
		safe_free(shell, (void **)&node->name);
	if (node->value)
		safe_free(shell, (void **)&node->value);
	safe_free(shell, (void **)&node);
}
