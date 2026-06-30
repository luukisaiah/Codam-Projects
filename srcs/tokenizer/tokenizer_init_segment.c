/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_init_segment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:06:16 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:07:15 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_segment	*init_segment(t_minishell *shell,
	t_lexer *lexer, t_tokenizer *tracker)
{
	t_token_segment	*segment;

	segment = safe_malloc(shell, sizeof(t_token_segment));
	segment->state = tracker->state;
	segment->start_pos = lexer->cur_pos;
	segment->end_pos = -1;
	return (segment);
}
