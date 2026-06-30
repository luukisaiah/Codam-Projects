/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:21:22 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 12:49:45 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args_array(t_minishell *shell, char **args) //
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		safe_free(shell, (void **)&args[i]);
		i++;
	}
	safe_free(shell, (void **)&args);
}

void	close_command_fds(t_command *cmd) //THIS IS NEEDED
{
	if (!cmd)
		return ;
	if (cmd->fd_input != STDIN_FILENO)
		close(cmd->fd_input);
	if (cmd->fd_output != STDOUT_FILENO)
		close(cmd->fd_output);
}

void	free_command(t_minishell *shell, t_command *cmd)
{
	if (!cmd)
		return ;
	close_command_fds(cmd);
	if (cmd->args)
		free_args_array(shell, cmd->args);
	if (cmd->redir_list)
		free_redir_list(shell, cmd->redir_list);
	safe_free(shell, (void **)&cmd);
}

int	handle_parse_error_cmd(t_minishell *shell,
	t_parser_state *state, t_command *cmd)
{
	if (state)
		state->has_error = 1;
	if (cmd)
		free_command(shell, cmd);
	return (0);
}
