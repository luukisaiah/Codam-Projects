/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helper_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:37:54 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 11:56:22 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_cd_minus(t_minishell *shell, t_env *env_list)
{
	char	*path;

	path = get_env_value(shell, env_list, "OLDPWD");
	if (!path)
	{
		write(2, "cd: OLDPWD not set\n", 19);
		return (NULL);
	}
	printf("%s\n", path);
	return (path);
}

char	*handle_tilde_path(char *arg, t_env *env_list,
		int *need_free, t_minishell *shell)
{
	char	*expanded;

	expanded = expand_tilde(arg, env_list, shell);
	if (!expanded)
	{
		write(2, "cd: HOME not set\n", 17);
		return (NULL);
	}
	if (expanded != arg)
		*need_free = 1;
	return (expanded);
}
