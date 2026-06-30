/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                            :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:25:10 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 12:16:40 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(t_minishell *mini, char **args, t_env *env_list)
{
	int		i;
	int		status;

	if (!args[1])
	{
		print_sorted_env(mini, env_list);
		return (0);
	}
	i = 1;
	status = 0;
	while (args[i])
	{
		if (!valid_identifiers(args[i]))
		{
			write(2, "export: `", 9);
			write(2, args[i], ft_strlen(args[i]));
			write(2, "': not a valid identifier\n", 26);
			status = 1;
			i++;
			continue ;
		}
		var_assig(mini, args[i], env_list);
		i++;
	}
	return (status);
}

void	var_assig(t_minishell *shell, char *args, t_env *env_list)
{
	char	*equal_sign;
	int		name_len;
	char	*name;
	char	*value;
	t_env	*node;

	equal_sign = ft_strchr(args, '=');
	if (equal_sign)
	{
		name_len = equal_sign - args;
		name = substr_safe(shell, args, 0, name_len);
		value = strdup_safe(shell, equal_sign + 1);
		node = find_env(env_list, name);
		if (node)
			node->value = value;
		else
			add_env_node(&env_list, new_env_node(shell, name, value));
	}
	else
	{
		node = find_env(env_list, args);
		if (!node)
			add_env_node(&env_list,
				new_env_node(shell, strdup_safe(shell, (args)), NULL));
	}
}
