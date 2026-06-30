/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_redirect_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:45:10 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:57:02 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	token_give_redirect_type(char c, char second_c)
{
	if (c == '|')
	{
		if (second_c == '|')
			return (T_OR);
		return (T_PIPE);
	}
	else if (c == '<')
	{
		if (second_c == '<')
			return (T_HERE_DOCUMENTS);
		return (T_REDIRECT_IN);
	}
	else if (c == '>')
	{
		if (second_c == '>')
			return (T_APPEND_TO);
		return (T_REDIRECT_OUT);
	}
	else if (c == '&')
	{
		if (second_c == '&')
			return (T_AND);
		return (T_ERROR);
	}
	return (T_ERROR);
}
