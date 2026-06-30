/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:50:01 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 15:53:23 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_list(t_minishell *shell, t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		if (tmp->name)
			safe_free(shell, (void **)&tmp->name);
		if (tmp->value)
			safe_free(shell, (void **)&tmp->value);
		env = env->next;
		if (tmp)
			safe_free(shell, (void **)&tmp);
	}
}
