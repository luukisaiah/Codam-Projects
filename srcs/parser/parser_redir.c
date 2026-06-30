/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:09:10 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/10 18:49:11 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir_type	convert_token_to_redir_type(t_token_type token_type)
{
	if (token_type == T_REDIRECT_IN)
		return (REDIR_IN);
	if (token_type == T_REDIRECT_OUT)
		return (REDIR_OUT);
	if (token_type == T_APPEND_TO)
		return (REDIR_APPEND);
	if (token_type == T_HERE_DOCUMENTS)
		return (REDIR_HEREDOC);
	return (REDIR_IN);
}

void	add_redirection_to_command(t_command *cmd, t_redir *redir)
{
	t_redir	*last;

	if (!cmd || !redir)
		return ;
	if (!cmd->redir_list)
	{
		cmd->redir_list = redir;
		return ;
	}
	last = cmd->redir_list;
	while (last->next)
		last = last->next;
	last->next = redir;
}

static int	validate_redir_token(t_parser_state *state,
		t_token **redir, t_token **file)
{
	*redir = get_current_token(state);
	if (!redir || !is_redirection_token((*redir)->type))
		return (0);
	advance_to_next_token(state);
	*file = get_current_token(state);
	if (!*file || !is_word_token((*file)->type))
		return (0);
	return (1);
}

static void	setup_heredoc_redir(t_minishell *shell,
		t_redir *redir, t_token *file_token)
{
	int	was_quoted;

	was_quoted = token_was_quoted(shell->input,
			file_token->pos, ft_strlen(file_token->value));
	redir->should_expand = !was_quoted;
	redir->file = strdup_safe(shell, file_token->value);
}

int	parse_single_redirection(t_minishell *shell,
		t_parser_state *state, t_command *cmd)
{
	t_token	*redir_token;
	t_token	*filenname_token;
	t_redir	*new_redir;

	if (!validate_redir_token(state, &redir_token, &filenname_token))
		return (0);
	new_redir = safe_malloc(shell, sizeof(t_redir));
	if (!new_redir)
		return (0);
	new_redir->type = convert_token_to_redir_type(redir_token->type);
	if (new_redir->type == REDIR_HEREDOC)
		setup_heredoc_redir(shell, new_redir, filenname_token);
	else
	{
		new_redir->file = strdup_safe(shell, filenname_token->value);
		new_redir->should_expand = 1;
	}
	new_redir->fd = -1;
	new_redir->next = NULL;
	add_redirection_to_command(cmd, new_redir);
	advance_to_next_token(state);
	return (1);
}
