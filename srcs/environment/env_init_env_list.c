/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_env_list.c                                 :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:48:58 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 13:12:06 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env_list(t_minishell *shell, char **environment)
{
	t_env	*head;
	t_env	*new_node;
	char	*name;
	char	*value;
	char	*equal_pos;

	head = NULL;
	while (*environment)
	{
		equal_pos = ft_strchr(*environment, '=');
		if (equal_pos)
		{
			name = substr_safe(shell,
					*environment, 0, equal_pos - *environment);
			if (!name)
				return (NULL);
			value = strdup_safe(shell, equal_pos + 1);
			new_node = new_env_node(shell, name, value);
			add_env_node(&head, new_node);
		}
		environment++;
	}
	return (head);
}

char	*get_env_value(t_minishell *shell, t_env *env_list, char *var_name)
{
	(void)shell;
	while (env_list)
	{
		if (ft_strcmp(env_list->name, var_name) == 0)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}
