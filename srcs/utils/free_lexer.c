/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:13:14 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 15:53:46 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_minishell *shell, t_lexer *lexer)
{
	if (lexer->input)
	{
		safe_free(shell, (void **)&(lexer->input));
		lexer->input = NULL;
	}
	safe_free(shell, (void **)&lexer);
	lexer = NULL;
}
