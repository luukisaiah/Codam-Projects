/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_check_normal_state.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:51:24 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:01:00 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer_normal_state(t_lexer *lexer, t_tokenizer *tracker)
{
	if (lexer->cur_char == '\'')
	{
		tracker->next_state = T_SQOUTE_STATE;
		tracker->action = T_CONTINUE;
	}
	else if (lexer->cur_char == '"')
	{
		tracker->next_state = T_DQUOTE_STATE;
		tracker->action = T_CONTINUE;
	}
	else if (ft_isredirect(lexer->cur_char))
		tracker->action = T_END_WORD;
	else if (ft_isspace(lexer->cur_char))
		tracker->action = T_END_WORD;
	else if (lexer->cur_char == '\0')
		tracker->action = T_END_WORD;
	else
		tracker->action = T_CONTINUE;
}
