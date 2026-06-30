/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper_redir.c                                 :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:39:50 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 13:08:08 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	save_file_descriptor(int *saved_fds)
{
	saved_fds[0] = dup(STDIN_FILENO);
	saved_fds[1] = dup(STDOUT_FILENO);
	saved_fds[2] = dup(STDERR_FILENO);
	if (saved_fds[0] == -1 || saved_fds[1] == -1 || saved_fds[2] == -1)
	{
		perror ("dup failed");
		return (1);
	}
	return (0);
}

void	restore_fds(int *saved_fds)
{
	dup2(saved_fds[0], STDIN_FILENO);
	dup2(saved_fds[1], STDOUT_FILENO);
	dup2(saved_fds[2], STDERR_FILENO);
	close(saved_fds[0]);
	close(saved_fds[1]);
	close(saved_fds[2]);
}

int	handle_parent_wait(t_minishell *shell, char**args, int status)
{
	if (WIFEXITED(status))
		shell->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_exit_status = 128 + WTERMSIG(status);
	handle_kill(status);
	handle_stopped(status, args);
	return (shell->last_exit_status);
}
