/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:04:36 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:12:39 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_safe(t_minishell *shell, char const *s, char c)
{
	char	**result;
	int		i;

	result = ft_split(s, c);
	check_malloc(shell, result);
	i = 0;
	while (result[i])
	{
		check_malloc(shell, result[i]);
		i++;
	}
	return (result);
}
