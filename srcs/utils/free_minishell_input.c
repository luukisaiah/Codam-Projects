/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:19:29 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:06:26 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell_input(t_minishell *shell)
{
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;
	}
	if (shell->lexer)
	{
		free_lexer(shell, shell->lexer);
		shell->lexer = NULL;
	}
	if (shell->tokens)
		lstclear_safe(shell, &shell->tokens, free_token_list);
	if (shell->parser_state)
	{
		safe_free(shell, (void **)&shell->parser_state);
		shell->parser_state = NULL;
	}
	if (shell->commands)
	{
		free_command_structure(shell, shell->commands);
		shell->commands = NULL;
	}
}
