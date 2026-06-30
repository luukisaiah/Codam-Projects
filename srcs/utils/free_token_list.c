/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:41:51 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:07:38 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	free_token(t_minishell *shell, t_token *token)
{
	if (token->value)
	{
		safe_free(shell, (void **)&(token->value));
		token->value = NULL;
	}
	safe_free(shell, (void **)&token);
	token = NULL;
}

void	free_token_list(t_minishell *shell, void *content)
{
	t_token	*token;

	token = (t_token *)content;
	free_token(shell, token);
}
