/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_extract_word_normal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:59:08 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:04:15 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_word_normal(t_minishell *shell,
	t_lexer *lexer, t_token_segment *segment)
{
	char	*content;
	char	*expanded;
	int		len;

	len = segment->end_pos - segment->start_pos;
	if (len <= 0)
		return (strdup_safe(shell, ""));
	content = substr_safe(shell, lexer->input, segment->start_pos, len);
	expanded = expand_one_arg(shell, content, shell->env_list);
	safe_free(shell, (void **)&content);
	return (expanded);
}
