/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_simple_commands.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/04 17:18:58 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:54:42 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_external(char **args, t_env *env_list, t_minishell *shell)
{
	pid_t	pid;
	int		status;
	int		result;

	pid = fork();
	if (pid == 0)
	{
		sig_restore();
		result = execute_ext_command(shell, args, env_list);
		if (shell)
		{
			free_minishell(shell);
		}
		exit(result);
	}
	else if (pid < 0)
		return (perror("fork"), (shell->last_exit_status = 1), 1);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, WUNTRACED);
	setup_sig();
	return (handle_parent_wait(shell, args, status));
}

int	exec_command(char **args, t_env *env_list, t_minishell *shell)
{
	if (!args || !args[0])
		return (0);
	if (is_builtin(args[0]))
		return (exec_built_ins(args, env_list, shell));
	else
		return (exec_external(args, env_list, shell));
}
