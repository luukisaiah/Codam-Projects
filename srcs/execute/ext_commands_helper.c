/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ext_commands_helper.c                               :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 18:16:15 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/05 12:13:23 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_no_path(char **envp, char **args_copy, char *cmd)
{
	printf("bash : %s: No such file or directory\n", cmd);
	free_array_untracked(envp);
	free_array_untracked(args_copy);
	return (1);
}

int	try_dirs_and_exec(t_minishell *shell,
	char **dir, char **args, t_exec_ctx *ctx)
{
	int		i;
	char	*full_path;
	char	*full_path_copy;

	i = 0;
	if (!*args[0] || !args[0])
		return (-1);
	while (dir[i])
	{
		full_path = join_path(shell, dir[i], args[0]);
		full_path_copy = ft_strdup(full_path);
		if (access(full_path, X_OK) == 0)
		{
			free_minishell(shell);
			execve(full_path_copy, ctx->args_copy, ctx->envp);
			free(full_path_copy);
			free_array_untracked(ctx->envp);
			free_array_untracked(ctx->args_copy);
			perror("execve");
			return (1);
		}
		free(full_path_copy);
		i++;
	}
	return (-1);
}
