/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:35:40 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 13:08:51 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_and_exit(t_minishell *mini)
{
	if (mini && mini->freelist)
		ft_lstclear(&(mini->freelist), free);
	exit(EXIT_FAILURE);
}
