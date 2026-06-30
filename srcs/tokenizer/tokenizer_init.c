/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:37:45 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:08:13 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokenizer	*tokenizer_init(t_minishell *shell, t_lexer *lexer)
{
	t_tokenizer			*tracker;
	t_token_segment		*first_segment;

	tracker = safe_malloc(shell, sizeof(t_tokenizer));
	tracker->prev_state = T_NORMAL_STATE;
	tokenizer_first_state(lexer, tracker);
	tracker->action = T_CONTINUE;
	tracker->segments = NULL;
	first_segment = init_segment(shell, lexer, tracker);
	tracker->segments = ft_lstnew_safe(shell, first_segment);
	tracker->cur_segment = first_segment;
	if (tracker->state == T_SQOUTE_STATE || tracker->state == T_DQUOTE_STATE)
		first_segment->start_pos = lexer->cur_pos + 1;
	else
		first_segment->start_pos = lexer->cur_pos;
	tracker->token_start = lexer->cur_pos;
	tracker->token_end = -1;
	tracker->error_msg = NULL;
	tracker->cur_segment->start_pos = lexer->cur_pos;
	tracker->cur_segment->end_pos = -1;
	return (tracker);
}
