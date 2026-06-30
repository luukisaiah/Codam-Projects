/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_extract_word_sq.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:18:19 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:04:42 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_word_sq(t_minishell *shell, t_lexer *lexer,
		t_token_segment *segment)
{
	char	*content;
	int		len;

	len = (segment->end_pos) - (segment->start_pos);
	if (len <= 0)
		return (strdup_safe(shell, ""));
	content = substr_safe(shell, lexer->input, segment->start_pos, len);
	return (content);
}
