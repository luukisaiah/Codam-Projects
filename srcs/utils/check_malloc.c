/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:45:27 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:09:03 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_malloc(t_minishell *mini, void *ptr)
{
	t_list	*new;

	if (ptr == NULL)
	{
		error_message("malloc", "can't allocate memory");
		cleanup_and_exit(mini);
	}
	else
	{
		new = ft_lstnew(ptr);
		if (new == NULL)
		{
			error_message("malloc", "can't allocate memory");
			cleanup_and_exit(mini);
		}
		else
			ft_lstadd_front(&(mini->freelist), new);
	}
}
