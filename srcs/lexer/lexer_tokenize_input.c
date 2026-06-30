/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_tokenize_input.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/08 14:33:34 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/07 16:02:18 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*tokenize_input(t_minishell *shell)
{
	t_list	*token_list;
	t_token	*token;
	t_lexer	*lexer;
	t_list	*new_node;

	lexer = shell->lexer;
	token_list = NULL;
	while (1)
	{
		token = get_next_token(shell, lexer);
		new_node = ft_lstnew_safe(shell, token);
		ft_lstadd_back(&token_list, new_node);
		if (token->type == T_ERROR || token->type == T_EOF)
			break ;
	}
	return (token_list);
}
