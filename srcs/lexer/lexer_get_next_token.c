/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:43:44 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:44:25 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_next_token(t_minishell *shell, t_lexer *lexer)
{
	t_token	*token;
	char	cur_c;

	token = NULL;
	while (ft_isspace(lexer->cur_char))
		next_char(lexer);
	cur_c = lexer->cur_char;
	if (cur_c == '\0')
		token = token_new(shell, T_EOF, NULL);
	else if (ft_isredirect(cur_c))
		token = token_redirects(shell, lexer);
	else if (cur_c >= 32 && cur_c <= 126)
		token = token_word(shell, lexer);
	else
		token = token_new(shell, T_ERROR, NULL);
	return (token);
}
