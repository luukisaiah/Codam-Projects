/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ext_commands.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/16 19:15:15 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/11/11 20:33:03 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(t_minishell *shell, char *dir, char *cmd)
{
	int		len;
	char	*full;
	int		i;

	len = ft_strlen(dir) + 1 + ft_strlen(cmd) + 1;
	full = safe_malloc(shell, len);
	if (!full)
		return (NULL);
	i = 0;
	while (*dir)
		full[i++] = *dir++;
	full[i++] = '/';
	while (*cmd)
		full[i++] = *cmd++;
	full[i] = '\0';
	return (full);
}

static int	is_direct_path(char *cmd)
{
	if (cmd[0] == '/')
		return (1);
	if (cmd[0] == '.' && cmd[1] == '/')
		return (1);
	if (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/')
		return (1);
	return (0);
}

static int	try_exec(t_minishell *shell, char *path,
	char **args, t_env *env_list)
{
	char	**envp;
	int		ret;
	int		saved_errno;
	char	**args_copy;
	char	*full_path_copy;

	(void)shell;
	envp = env_list_to_envp_untracked(env_list);
	args_copy = copy_string_arr(args);
	full_path_copy = ft_strdup(path);
	free_minishell(shell);
	execve(full_path_copy, args_copy, envp);
	saved_errno = errno;
	perror("execve");
	if (saved_errno == ENOENT)
		ret = 127;
	else
		ret = (126);
	free_array_untracked(envp);
	free_array_untracked(args_copy);
	if (full_path_copy)
		free(full_path_copy);
	return (ret);
}

int	search_n_exec(t_minishell *shell, char **args, t_env *env_list)
{
	char		*path_env;
	char		**dir;
	t_exec_ctx	ctx;

	ctx.envp = env_list_to_envp_untracked(env_list);
	ctx.args_copy = copy_string_arr(args);
	path_env = get_env_value(shell, env_list, "PATH");
	if (!path_env || !*path_env)
		return (handle_no_path(ctx.envp, ctx.args_copy, args[0]));
	dir = split_safe(shell, path_env, ':');
	if (try_dirs_and_exec(shell, dir, args, &ctx) != -1)
		return (1);
	write(2, "\"", 1);
	write(2, args[0], ft_strlen(args[0]));
	write(2, "\"", 1);
	write(2, ": command not found\n", 20);
	free_array(shell, dir);
	free_array_untracked(ctx.envp);
	free_array_untracked(ctx.args_copy);
	shell->last_exit_status = 127;
	return (127);
}

int	execute_ext_command(t_minishell *shell, char **args, t_env *env_list)
{
	if (!args || !args[0])
		return (1);
	if (is_direct_path(args[0]))
		return (try_exec(shell, args[0], args, env_list));
	return (search_n_exec(shell, args, env_list));
}
