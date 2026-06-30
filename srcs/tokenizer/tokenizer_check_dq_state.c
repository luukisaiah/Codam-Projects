/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_check_dq_state.c                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:11:24 by lderks            #+#    #+#             */
/*   Updated: 2025/11/11 12:16:02 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer_dq_state(t_lexer *lexer, t_tokenizer *tracker)
{
	if (lexer->cur_char == '"')
	{
		tracker->next_state = T_NORMAL_STATE;
		tracker->action = T_CONTINUE;
	}
	else if (lexer->cur_char == '\0')
	{
		tracker->action = T_ERROR_A;
		tracker->error_msg = "Unclosed double quote";
	}
	else
		tracker->action = T_CONTINUE;
}
