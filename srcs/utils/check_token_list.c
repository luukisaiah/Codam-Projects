/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_token_list.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/21 15:25:39 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/08 14:06:21 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_token_from_list(t_list *list)
{
	if (!list)
		return (NULL);
	return ((t_token *)list->content);
}

static int	redir_check_type(t_token_type type)
{
	if (type == T_REDIRECT_IN)
		return (1);
	else if (type == T_HERE_DOCUMENTS)
		return (1);
	else if (type == T_REDIRECT_OUT)
		return (1);
	else if (type == T_APPEND_TO)
		return (1);
	else if (type == T_PIPE)
		return (1);
	return (0);
}

int	handle_syntax_error(t_list *current, t_token *token, t_token *next_token)
{
	if (redir_check_type(token->type))
	{
		if (!current->next)
			return (printf("Error: syntax error\n"), 0);
		next_token = get_token_from_list(current->next);
		if (next_token->type != T_WORD)
			return (printf("Error: syntax error\n"), 0);
	}
	return (1);
}

int	check_token_list(t_list *token_list)
{
	t_list	*current;
	t_token	*token;
	t_token	*next_token;

	current = token_list;
	token = get_token_from_list(current);
	if (token->type == T_PIPE)
		return ((printf("Error: syntax error\n"), 0));
	while (current)
	{
		token = get_token_from_list(current);
		if (current->next)
			next_token = get_token_from_list(current->next);
		else
			next_token = NULL;
		if (token->type == T_ERROR)
			return (printf("Error: %s\n", token->value), 0);
		if (token->type == T_AND || token->type == T_OR)
			return (printf("Error: Logical operator not supported\n"), 0);
		if (!handle_syntax_error(current, token, next_token))
			return (0);
		current = current->next;
	}
	return (1);
}
