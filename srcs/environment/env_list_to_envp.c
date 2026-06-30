/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:52:53 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 12:01:46 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_env_vars(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		if (env->name && env->value)
			count++;
		env = env->next;
	}
	return (count);
}

char	**env_list_to_envp(t_minishell *shell, t_env *env)
{
	int		i;
	int		size;
	char	**envp;
	char	*joined;

	i = 0;
	size = count_env_vars(env);
	envp = safe_malloc(shell, sizeof(char *) * (size + 1));
	while (env)
	{
		if (env->name && env->value)
		{
			joined = strjoin_safe(shell, env->name, "=");
			envp[i] = strjoin_safe(shell, joined, env->value);
			safe_free(shell, (void **)&joined);
			i++;
		}
		env = env->next;
	}
	envp[i] = NULL;
	return (envp);
}
