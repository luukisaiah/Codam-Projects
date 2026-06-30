/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:25:31 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 12:17:32 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_minishell *shell, char **args, t_env *env_list)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if ((valid_identifiers(args[i]) && !ft_strchr(args[i], '='))
			&& !ft_strchr(args[i], '+'))
			remove_env_var(shell, env_list, args[i]);
		else
			printf("unset: '%s': not a valid identifier\n", args[i]);
		i++;
	}
	return (0);
}
