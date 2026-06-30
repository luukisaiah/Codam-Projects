/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_redirections.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 16:47:26 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:39:54 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_heredoc_redir(t_redir *redir)
{
	if (redir->fd < 0)
		return (-1);
	if (dup2(redir->fd, STDIN_FILENO) < 0)
		return (perror("dup2"), -1);
	close(redir->fd);
	return (0);
}

int	apply_redirections(t_redir *redir_list)
{
	while (redir_list)
	{
		if (redir_list->type == REDIR_IN)
		{
			if (handle_input_redirection(redir_list->file) < 0)
				return (-1);
		}
		else if (redir_list->type == REDIR_OUT)
		{
			if (handle_output_redirection(redir_list->file) < 0)
				return (-1);
		}
		else if (redir_list->type == REDIR_APPEND)
		{
			if (handle_append_redirection(redir_list->file) < 0)
				return (-1);
		}
		else if (redir_list->type == REDIR_HEREDOC)
		{
			if (handle_heredoc_redir(redir_list) < 0)
				return (-1);
		}
		redir_list = redir_list->next;
	}
	return (0);
}
