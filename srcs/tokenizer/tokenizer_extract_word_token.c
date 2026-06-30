/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_extract_word_token.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:01:58 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:38:18 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*extract_word_token(t_minishell *shell, t_lexer *lexer,
		t_tokenizer *tracker)
{
	t_token_segment	*cur_segment;
	t_token			*token;
	t_list			*segment_node;
	char			*segment_content;
	char			*result;

	result = strdup_safe(shell, "");
	segment_node = tracker->segments;
	while (segment_node)
	{
		cur_segment = (t_token_segment *)segment_node->content;
		if (cur_segment->state == T_NORMAL_STATE)
			segment_content = extract_word_normal(shell, lexer, cur_segment);
		else if (cur_segment->state == T_SQOUTE_STATE)
			segment_content = extract_word_sq(shell, lexer, cur_segment);
		else if (cur_segment->state == T_DQUOTE_STATE)
			segment_content = extract_word_dq(shell, lexer, cur_segment);
		else
			return (token_new(shell, T_ERROR, "Failed to set state"));
		result = strjoin_safe(shell, result, segment_content);
		safe_free(shell, (void **)&segment_content);
		segment_node = segment_node->next;
	}
	return (token = token_new(shell, T_WORD, result),
		safe_free(shell, (void **)&result), token);
}
