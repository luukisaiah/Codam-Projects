/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_segment_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:10:34 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:07:02 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_segment_list(t_minishell *shell, void *content)
{
	t_token_segment	*segment;

	segment = (t_token_segment *)content;
	safe_free(shell, (void **)&segment);
}
