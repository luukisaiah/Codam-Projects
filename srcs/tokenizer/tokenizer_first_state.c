/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_first_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:20:22 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:06:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer_first_state(t_lexer *lexer, t_tokenizer *tracker)
{
	if (lexer->cur_char == '\'')
	{
		tracker->state = T_SQOUTE_STATE;
		tracker->next_state = T_SQOUTE_STATE;
		next_char(lexer);
	}
	else if (lexer->cur_char == '"')
	{
		tracker->state = T_DQUOTE_STATE;
		tracker->next_state = T_DQUOTE_STATE;
		next_char(lexer);
	}
	else
	{
		tracker->state = T_NORMAL_STATE;
		tracker->next_state = T_NORMAL_STATE;
	}
}
