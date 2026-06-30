/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_redir_commands.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/25 19:17:55 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:54:48 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_redir_only(t_command *cmd, t_minishell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (apply_redirections(cmd->redir_list) != 0)
		{
			free_minishell(shell);
			exit(1);
		}
		free_minishell(shell);
		exit(0);
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_sig();
	if (WIFEXITED(status))
		shell->last_exit_status = WEXITSTATUS(status);
	return (shell->last_exit_status);
}

static void	child_extern_exec(t_command *cmd,
	t_env *env_list, t_minishell *shell)
{
	int	result;

	sig_restore();
	if (apply_redirections(cmd->redir_list) != 0)
	{
		free_minishell(shell);
		exit(1);
	}
	result = execute_ext_command(shell, cmd->args, env_list);
	if (shell)
	{
		free_minishell(shell);
		shell = NULL;
	}
	exit(result);
}

int	exec_external_with_redir(t_command *cmd,
	t_env *env_list, t_minishell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		child_extern_exec(cmd, env_list, shell);
	else if (pid < 0)
		return (perror("fork"), shell->last_exit_status = 1, 1);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, WUNTRACED);
	setup_sig();
	handle_parent_wait(shell, cmd->args, status);
	return (shell->last_exit_status);
}

int	exec_command_with_redir(t_command *cmd, t_env *env_list, t_minishell *shell)
{
	if (!cmd->args || !cmd->args[0])
		return (exec_redir_only(cmd, shell));
	cmd->args = expand_args(cmd->args, env_list, shell);
	if (!cmd->args || !cmd->args[0])
		return (exec_redir_only(cmd, shell));
	if (cmd->args[0][0] == '\0')
	{
		write(2, "\"\": command not found\n", 22);
		shell->last_exit_status = 127;
		return (127);
	}
	if (is_builtin(cmd->args[0]))
		return (exec_builtin_in_parent_with_redir (cmd, env_list, shell));
	else
		return (exec_external_with_redir(cmd, env_list, shell));
}

int	exec_builtin_in_parent_with_redir(t_command *cmd,
		t_env *env_list, t_minishell *shell)
{
	int	saved_fds[3];
	int	result;

	if (save_file_descriptor(saved_fds) != 0)
		return (1);
	if (apply_redirections(cmd->redir_list) != 0)
	{
		restore_fds(saved_fds);
		return (1);
	}
	result = exec_built_ins(cmd->args, env_list, shell);
	restore_fds(saved_fds);
	return (result);
}
