/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_check_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:41:26 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:02:35 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer_check_state(t_minishell *shell,
		t_lexer *lexer, t_tokenizer *tracker)
{
	t_token_segment	*new_segment;
	t_list			*new_node;

	if (tracker->next_state != tracker->state)
	{
		if (tracker->cur_segment)
			tracker->cur_segment->end_pos = lexer->cur_pos;
		new_segment = safe_malloc(shell, sizeof(t_token_segment));
		new_segment->state = tracker->next_state;
		new_segment->start_pos = lexer->cur_pos + 1;
		new_segment->end_pos = -1;
		new_node = ft_lstnew_safe(shell, new_segment);
		ft_lstadd_back(&tracker->segments, new_node);
		tracker->cur_segment = new_segment;
		tracker->prev_state = tracker->state;
		tracker->state = tracker->next_state;
	}
}
