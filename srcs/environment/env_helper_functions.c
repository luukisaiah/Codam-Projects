/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper_functions.c                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:12:21 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 13:11:02 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env_node(t_minishell *shell, char *name, char *value)
{
	t_env	*node;

	node = safe_malloc(shell, sizeof (t_env));
	if (!node)
		return (NULL);
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_env_node(t_env **head, t_env *node_toadd)
{
	t_env	*current;

	if (!head || !node_toadd)
		return ;
	if (*head == NULL)
	{
		*head = node_toadd;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = node_toadd;
}

t_env	*find_env(t_env *env_list, char *name)
{
	while (env_list)
	{
		if ((ft_strcmp(env_list->name, name)) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

int	valid_identifiers(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (!isalpha(str[0]) && str [0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	set_env_value(t_minishell *shell, t_env *env_list,
			char *name, char *value)
{
	char	*tmp;
	char	*assignment;

	tmp = strjoin_safe(shell, name, "=");
	assignment = strjoin_safe(shell, tmp, value);
	var_assig(shell, assignment, env_list);
}
