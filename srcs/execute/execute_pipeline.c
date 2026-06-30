/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_pipeline.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/25 17:14:24 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:20:54 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipeline(t_command *cmd_list, t_env *env_list, t_minishell *shell)
{
	int	cmd_count;

	cmd_count = count_commands(cmd_list);
	if (process_heredocs(shell, cmd_list) < 0)
		return (shell->last_exit_status);
	if (cmd_count == 1)
	{
		return (exec_command_with_redir(cmd_list, env_list, shell));
	}
	else
	{
		return (execute_multiple_pipes(cmd_list, env_list, shell, cmd_count));
	}
}
