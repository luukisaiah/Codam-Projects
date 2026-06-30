/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:50:27 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/10 18:38:12 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_heredocs(t_minishell *shell, t_command *cmd_list)
{
	t_command	*current;
	t_redir		*redir;

	current = cmd_list;
	while (current)
	{
		redir = current->redir_list;
		while (redir)
		{
			if (redir->type == REDIR_HEREDOC)
			{
				redir->fd = handle_heredoc_redirection(shell, redir->file,
						redir->should_expand);
				if (redir->fd < 0)
					return (-1);
			}
			redir = redir->next;
		}
		current = current->next;
	}
	return (0);
}
