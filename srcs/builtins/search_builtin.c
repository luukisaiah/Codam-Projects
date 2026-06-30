/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:15:49 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 12:17:00 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

int	exec_built_ins(char **args, t_env *env_list, t_minishell *shell)
{
	int	status;

	status = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		status = builtin_echo(args);
	if (ft_strcmp(args[0], "pwd") == 0)
		status = builtin_pwd();
	if (ft_strcmp(args[0], "cd") == 0)
		status = builtin_cd(args, env_list, shell);
	if (ft_strcmp(args[0], "export") == 0)
		status = builtin_export(shell, args, env_list);
	if (ft_strcmp(args[0], "unset") == 0)
		status = builtin_unset(shell, args, env_list);
	if (ft_strcmp(args[0], "env") == 0)
	{
		if (!args[1])
			status = builtin_env(env_list);
		else
			status = handle_env_with_arg(args, env_list, shell);
	}
	else if (ft_strcmp(args[0], "exit") == 0)
		status = builtin_exit(shell, args);
	shell->last_exit_status = status;
	return (status);
}

int	handle_env_with_arg(char **args, t_env *env_list, t_minishell *shell)
{
	args = expand_args(args, env_list, shell);
	if (!is_builtin(args[1]))
	{
		write(2, "env: ", 5);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": No such file or directory\n", 28);
		return (127);
	}
	if (is_builtin(args[1]))
		return (exec_built_ins(&args[1], env_list, shell));
	else
		return (execute_ext_command(shell, &args[1], env_list));
}
