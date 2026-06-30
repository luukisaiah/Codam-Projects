/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handling.c                                  :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:11:28 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 13:15:28 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_stopped(int status, char **args)
{
	if (WIFSTOPPED(status))
	{
		write(STDOUT_FILENO, "\n[1]+  Stopped                 ", 32);
		write(STDOUT_FILENO, args[0], ft_strlen(args[0]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	handle_kill(int status)
{
	int		sig;

	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGQUIT)
			write(STDOUT_FILENO, "Quit (core dumped)\n", 20);
		else if (sig == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
	}
}

void	handle_exit(int status)
{
	int		exit_code;

	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		printf("Exited normally with code %d\n", exit_code);
	}
}
