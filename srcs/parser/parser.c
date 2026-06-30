/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/11 17:37:52 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:46:09 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_redir_token_parser(t_minishell *shell,
	t_parser_state *state, t_command *cmd)
{
	if (!parse_single_redirection(shell, state, cmd))
	{
		handle_parse_error_cmd(shell, state, cmd);
		return (0);
	}
	return (1);
}

t_command	*parse_simple_command(t_minishell *shell, t_parser_state *state)
{
	t_command	*cmd;
	t_token		*token;

	cmd = init_command(shell);
	if (!cmd)
		return (NULL);
	token = get_current_token(state);
	while (token != NULL && !is_command_end_token(token->type))
	{
		if (is_word_token(token->type))
		{
			add_arg(shell, cmd, token->value);
			advance_to_next_token(state);
		}
		else if (is_redirection_token(token->type))
		{
			if (!handle_redir_token_parser(shell, state, cmd))
				return (NULL);
		}
		else
			advance_to_next_token(state);
		token = get_current_token(state);
	}
	return (cmd);
}
