/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:38:17 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 13:24:18 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipes_cleanup(t_minishell *shell, int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		if (pipes[i])
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
			safe_free(shell, (void **)&pipes[i]);
		}
		i++;
	}
	safe_free(shell, (void **)&pipes);
}

int	count_commands(t_command *cmd_list)
{
	int	count;

	count = 0;
	while (cmd_list)
	{
		count ++;
		cmd_list = cmd_list->next;
	}
	return (count);
}

int	**create_pipes(t_minishell *shell, int num_pipes)
{
	int	**pipes;
	int	i;

	pipes = safe_malloc(shell, sizeof(int *) * num_pipes);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < num_pipes)
	{
		pipes[i] = safe_malloc(shell, sizeof(int) * 2);
		if (!pipes[i])
		{
			pipes_cleanup(shell, pipes, i);
			return (NULL);
		}
		if (pipe(pipes[i]) == -1)
		{
			safe_free(shell, (void **)&pipes[i]);
			pipes_cleanup(shell, pipes, i);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	close_all_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
