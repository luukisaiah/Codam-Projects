/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                                :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:23:27 by doda-cun          #+#    #+#             */
/*   Updated: 2025/12/02 20:07:14 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char **args, t_env *env_list, t_minishell *shell)
{
	char	*path;
	int		need_free;

	if (args[1] && args[2])
		return (write(2, "cd: too many arguments\n", 23), 1);
	need_free = 0;
	if (!args[1] || ft_strcmp(args[1], "~") == 0)
		path = get_env_value(shell, env_list, "HOME");
	else if (ft_strcmp(args[1], "-") == 0)
		path = handle_cd_minus(shell, env_list);
	else
		path = handle_tilde_path(args[1], env_list, &need_free, shell);
	if (!path)
		return (write(2, "cd: HOME not set\n", 17), 1);
	if (chdir(path) != 0)
		return (perror("cd"), need_free && (free(path), 0), 1);
	update_pwd(shell, env_list);
	if (need_free)
		free(path);
	return (0);
}
