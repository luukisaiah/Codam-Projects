/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:01:11 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 12:19:31 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*parse_pipeline(t_minishell *shell, t_parser_state *state)
{
	t_command	*first_cmd;
	t_command	*current_cmd;
	t_command	*new_cmd;
	t_token		*token;

	first_cmd = parse_simple_command(shell, state);
	if (!first_cmd)
		return (NULL);
	current_cmd = first_cmd;
	token = get_current_token(state);
	while (token && token->type == T_PIPE)
	{
		advance_to_next_token(state);
		new_cmd = parse_simple_command(shell, state);
		if (!new_cmd)
			return (free_command_pipeline(shell, first_cmd), NULL);
		current_cmd->next = new_cmd;
		current_cmd = new_cmd;
		token = get_current_token(state);
	}
	if (handle_logical_op_error(shell, token, first_cmd))
		return (NULL);
	return (first_cmd);
}

void	free_command_pipeline(t_minishell *shell, t_command *pipeline)
{
	t_command	*current;
	t_command	*next;

	current = pipeline;
	while (current)
	{
		next = current->next;
		free_command(shell, current);
		current = next;
	}
}
