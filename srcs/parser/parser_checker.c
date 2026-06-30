/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_checker.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/16 17:20:03 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/10/07 12:46:24 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command_end_token(t_token_type type)
{
	if (type == T_PIPE || type == T_EOF)
		return (1);
	return (0);
}

int	is_word_token(t_token_type type)
{
	if (type == T_WORD)
		return (1);
	return (0);
}

int	is_redirection_token(t_token_type type)
{
	if (type == T_REDIRECT_IN || type == T_REDIRECT_OUT
		|| type == T_APPEND_TO || type == T_HERE_DOCUMENTS)
		return (1);
	return (0);
}
