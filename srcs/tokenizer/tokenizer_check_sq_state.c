/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_check_sq_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:11:24 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:01:39 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer_sq_state(t_lexer *lexer, t_tokenizer *tracker)
{
	if (lexer->cur_char == '\'')
	{
		tracker->next_state = T_NORMAL_STATE;
		tracker->action = T_CONTINUE;
	}
	else if (lexer->cur_char == '\0')
	{
		tracker->action = T_ERROR_A;
		tracker->error_msg = "Unclosed single quote";
	}
	else
		tracker->action = T_CONTINUE;
}
