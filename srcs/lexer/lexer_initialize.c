/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_initialize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/04 17:07:36 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/07 16:01:17 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_initialize(t_minishell *shell)
{
	t_lexer	*lexer;

	lexer = safe_malloc(shell, sizeof(t_lexer));
	lexer->input = strdup_safe(shell, shell->input);
	lexer->cur_pos = 0;
	if (ft_strlen(lexer->input) > 0)
	{
		lexer->cur_char = lexer->input[0];
		lexer->next_pos = 1;
	}
	else
	{
		lexer->cur_char = '\0';
		lexer->next_pos = 0;
	}
	return (lexer);
}
