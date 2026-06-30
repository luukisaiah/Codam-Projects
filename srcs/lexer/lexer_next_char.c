/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_next_char.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/08 16:13:03 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/07 16:01:23 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_char(t_lexer *lexer)
{
	if (ft_strlen(lexer->input) <= (size_t)lexer->next_pos)
	{
		lexer->cur_char = '\0';
		return ;
	}
	lexer->cur_char = lexer->input[lexer->next_pos];
	lexer->cur_pos = lexer->next_pos;
	lexer->next_pos++;
}
