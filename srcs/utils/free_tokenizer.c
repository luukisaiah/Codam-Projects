/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:49:36 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:07:59 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokenizer(t_minishell *shell, t_tokenizer *tracker)
{
	if (!tracker)
		return ;
	if (tracker->segments)
		lstclear_safe(shell, &(tracker->segments), free_segment_list);
	safe_free(shell, (void **)&tracker);
}
