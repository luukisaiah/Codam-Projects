/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:49:50 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 12:51:45 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_current_token(t_parser_state *state)
{
	if (!state || !state->current_token)
		return (NULL);
	return ((t_token *)state->current_token->content);
}

void	advance_to_next_token(t_parser_state *state)
{
	if (!state || !state->current_token)
		return ;
	state->current_token = state->current_token->next;
}

t_command	*init_command(t_minishell *shell)
{
	t_command	*cmd;

	cmd = safe_malloc(shell, sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redir_list = NULL;
	cmd->fd_input = STDIN_FILENO;
	cmd->fd_output = STDOUT_FILENO;
	cmd->pid = -1;
	cmd->exit_status = 0;
	cmd->next = NULL;
	return (cmd);
}

int	handle_logical_op_error(t_minishell *shell, t_token *token,
			t_command *pipeline)
{
	if (!token)
		return (0);
	if (token->type == T_AND || token->type == T_OR)
	{
		printf("minishell:syntax error: logical operator not supported");
		if (pipeline)
			free_command_pipeline(shell, pipeline);
		return (1);
	}
	return (0);
}

char	**expand_args(char **args, t_env *env_list, t_minishell *shell)
{
	int		i;
	char	*expanded;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '~')
		{
			expanded = expand_tilde(args[i], env_list, shell);
			if (expanded && expanded != args[i])
				args[i] = expanded;
		}
		i++;
	}
	return (args);
}
