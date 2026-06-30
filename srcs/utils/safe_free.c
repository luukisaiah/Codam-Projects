/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:21:39 by lderks            #+#    #+#             */
/*   Updated: 2025/11/11 13:19:25 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_free(t_minishell *shell, void **ptr)
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = shell->freelist;
	if (*ptr)
	{
		while (cur)
		{
			if (cur->content == *ptr)
			{
				if (prev)
					prev->next = cur->next;
				else
					shell->freelist = cur->next;
				free(*ptr);
				free(cur);
				*ptr = NULL;
				return ;
			}
			prev = cur;
			cur = cur->next;
		}
	}
	*ptr = NULL;
}
