/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/08 16:49:05 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/07 16:07:33 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_new(t_minishell *shell, t_token_type type, char *content)
{
	t_token	*token;

	if (!shell || !shell->lexer)
		return (NULL);
	token = safe_malloc(shell, sizeof(t_token));
	token->type = type;
	token->pos = shell->lexer->cur_pos;
	if (content)
		token->value = strdup_safe(shell, content);
	else
		token->value = NULL;
	return (token);
}
