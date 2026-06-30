/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multiple_pipes_helper_functions.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 15:30:53 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:54:39 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	clean_and_exit(t_minishell *shell, int exit_code)
{
	free_minishell(shell);
	return (exit_code);
}

void	execute_child_free_exit(t_minishell *shell, int exit_code)
{
	free_minishell(shell);
	exit(exit_code);
}

int	builtin_exit_in_pipe(t_minishell *shell, char **args)
{
	if (!args[1])
	{
		shell->should_exit = 1;
		shell->exit_status = 0;
		return (0);
	}
	if (!is_numeric(args[1]))
	{
		shell->should_exit = 1;
		shell->exit_status = 2;
		write(2, "exit: ", 6);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		return (2);
	}
	if (args[2])
	{
		write(2, "exit\n", 5);
		write(2, "exit: too many arguments\n", 25);
		return (1);
	}
	shell->exit_status = ft_atoi(args[1]) % 256;
	shell->should_exit = 1;
	return (shell->exit_status);
}

int	wait_for_all(int *pids, int cmd_count, t_minishell *shell)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	last_status = 0;
	while (i < cmd_count)
	{
		waitpid(pids[i], &status, 0);
		if (i == cmd_count - 1)
		{
			if (WIFEXITED(status))
				last_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				last_status = 128 + WTERMSIG(status);
				handle_kill(status);
			}
		}
		i++;
	}
	shell->last_exit_status = last_status;
	return (last_status);
}
