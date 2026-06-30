/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:11:15 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:05:38 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(char *function, char *message)
{
	int	saved_errno;

	saved_errno = errno;
	if (!function && !message && saved_errno)
		perror("minishell");
	else
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		if (function)
			ft_putstr_fd(function, STDERR_FILENO);
		if (message)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(message, STDERR_FILENO);
		}
		if (saved_errno)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(strerror(saved_errno), STDERR_FILENO);
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	errno = 0;
}
