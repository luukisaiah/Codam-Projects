/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_parserstate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:45:26 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:50:11 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser_state	*init_parser_state(t_minishell *shell)
{
	t_parser_state	*parser_state;

	parser_state = safe_malloc(shell, sizeof(t_parser_state));
	parser_state->current_token = shell->tokens;
	parser_state->has_error = 0;
	return (parser_state);
}
