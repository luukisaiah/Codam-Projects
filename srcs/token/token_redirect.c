/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:44:58 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:58:36 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*token_convert_type(t_token_type type)
{
	if (type == T_REDIRECT_IN)
		return ("<");
	else if (type == T_HERE_DOCUMENTS)
		return ("<<");
	else if (type == T_REDIRECT_OUT)
		return (">");
	else if (type == T_APPEND_TO)
		return (">>");
	else if (type == T_PIPE)
		return ("|");
	else if (type == T_OR)
		return ("||");
	else if (type == T_AND)
		return ("&&");
	return (NULL);
}

t_token	*token_redirects(t_minishell *shell, t_lexer *lexer)
{
	char			second_c;
	t_token			*token;
	t_token_type	type;
	char			*content;

	second_c = lexer->input[lexer->next_pos];
	type = token_give_redirect_type(lexer->cur_char, second_c);
	content = token_convert_type(type);
	token = token_new(shell, type, content);
	if (lexer->cur_char == second_c)
		next_char(lexer);
	next_char(lexer);
	return (token);
}
