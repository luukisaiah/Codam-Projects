/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/21 17:55:28 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 15:01:06 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_was_quoted(char *input, int token_pos, int token_len)
{
	int		quote_pos1;
	int		quote_pos2;

	quote_pos1 = token_pos - token_len - 1;
	quote_pos2 = token_pos - token_len - 2;
	if (quote_pos1 >= 0
		&& (input[quote_pos1] == '\'' || input[quote_pos1] == '"'))
		return (1);
	if (quote_pos2 >= 0
		&& (input[quote_pos2] == '\'' || input[quote_pos2] == '"'))
		return (1);
	return (0);
}

int	is_heredoc_end(char *line, char *delimiter)
{
	if (!line)
	{
		if (g_signal_flag != SIGINT)
		{
			printf("minishell: warning: here-document delimited");
			printf(" by end-of-file(wanted `%s')\n", delimiter);
		}
		return (1);
	}
	if (ft_strcmp(line, delimiter) == 0)
		return (free(line), 1);
	return (0);
}

void	heredoc_child_cleanup(t_minishell *shell)
{
	if (!shell)
		return ;
	free_minishell(shell);
	rl_clear_history();
	get_next_line(-1);
}
