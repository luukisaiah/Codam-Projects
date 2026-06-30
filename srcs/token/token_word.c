/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:51:46 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:59:44 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_token_states(t_minishell *shell, t_lexer *lexer,
				t_tokenizer *tracker)
{
	while (tracker->action != T_END_WORD && tracker->action != T_ERROR_A)
	{
		if (tracker->state == T_NORMAL_STATE)
			tokenizer_normal_state(lexer, tracker);
		else if (tracker->state == T_SQOUTE_STATE)
			tokenizer_sq_state(lexer, tracker);
		else if (tracker->state == T_DQUOTE_STATE)
			tokenizer_dq_state(lexer, tracker);
		tokenizer_check_state(shell, lexer, tracker);
		if (tracker->action == T_CONTINUE)
			next_char(lexer);
	}
}

t_token	*token_word(t_minishell *shell, t_lexer *lexer)
{
	t_tokenizer	*tracker;
	t_token		*token;

	tracker = tokenizer_init(shell, lexer);
	process_token_states(shell, lexer, tracker);
	if (tracker->action == T_ERROR_A)
	{
		token = token_new(shell, T_ERROR,
				strdup_safe(shell, tracker->error_msg));
		free_tokenizer(shell, tracker);
		return (token);
	}
	if (tracker->cur_segment)
	{
		if (ft_isspace(lexer->cur_char) || ft_isredirect(lexer->cur_char))
			tracker->cur_segment->end_pos = lexer->cur_pos;
		else
			tracker->cur_segment->end_pos = lexer->cur_pos + 1;
		tracker->token_end = tracker->cur_segment->end_pos;
	}
	token = extract_word_token(shell, lexer, tracker);
	free_tokenizer(shell, tracker);
	return (token);
}
