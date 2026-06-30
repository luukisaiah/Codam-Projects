/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                       :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:09:36 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 12:19:20 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_arg(t_minishell *shell, t_command *cmd, char *word)
{
	int		count;
	char	**new_argv;
	int		i;

	count = 0;
	if (!cmd || !word)
		return ;
	if (cmd->args)
	{
		while (cmd->args[count])
			count++;
	}
	new_argv = safe_malloc(shell, sizeof(char *) * (count + 2));
	i = 0;
	while (i < count)
	{
		new_argv[i] = cmd->args[i];
		i++;
	}
	new_argv[count] = strdup_safe(shell, word);
	new_argv[count + 1] = NULL;
	cmd->args = new_argv;
}

int	process_word_token(t_minishell *shell,
		t_parser_state *state, t_command *cmd)
{
	t_token	*token;

	token = get_current_token(state);
	if (!token || !is_word_token(token->type))
		return (0);
	add_arg(shell, cmd, token->value);
	advance_to_next_token(state);
	return (1);
}
