/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipes_execution.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 15:26:15 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 13:52:45 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_multiple_pipes(t_command *cmd_list, t_env *env_list,
		t_minishell *shell, int cmd_count)
{
	t_pipe_data	data;
	int			status;

	data.pipes = create_pipes(shell, cmd_count - 1);
	if (!data.pipes)
		return (1);
	data.pids = safe_malloc(shell, sizeof(int) * cmd_count);
	if (!data.pids)
	{
		pipes_cleanup(shell, data.pipes, cmd_count - 1);
		return (1);
	}
	data.env_list = env_list;
	data.last_exit_status = shell->last_exit_status;
	data.num_pipes = cmd_count - 1;
	data.num_cmds = cmd_count;
	execute_all_commands(shell, cmd_list, &data);
	pipes_cleanup(shell, data.pipes, cmd_count - 1);
	status = wait_for_all(data.pids, cmd_count, shell);
	safe_free(shell, (void **)&data.pids);
	return (status);
}

void	execute_child(t_minishell *shell, t_command *cmd, t_pipe_data *data,
			int index)
{
	int	exit_code;

	sig_restore();
	if (index > 0)
		dup2(data->pipes[index - 1][0], STDIN_FILENO);
	if (index < data->num_cmds - 1)
		dup2(data->pipes[index][1], STDOUT_FILENO);
	close_all_pipes(data->pipes, data->num_pipes);
	if (apply_redirections (cmd->redir_list) < 0)
		exit(clean_and_exit(shell, 1));
	if (is_builtin(cmd->args[0]))
	{
		if (ft_strcmp(cmd->args[0], "exit") == 0)
			exit_code = builtin_exit_in_pipe(shell, cmd->args);
		else
			exit_code = exec_built_ins(cmd->args, data->env_list, shell);
		execute_child_free_exit(shell, exit_code);
	}
	else
	{
		exit_code = execute_ext_command(shell, cmd->args, data->env_list);
		free_minishell(shell);
		exit(exit_code);
	}
}

void	execute_all_commands(t_minishell *shell, t_command *cmd_list,
			t_pipe_data *data)
{
	int			i;
	t_command	*current;

	i = 0;
	current = cmd_list;
	while (current)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
			execute_child(shell, current, data, i);
		i++;
		current = current-> next;
	}
}
