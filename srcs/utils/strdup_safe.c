/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:12:16 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:12:46 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strdup_safe(t_minishell *mini, const char *str)
{
	char	*fresh_str;

	if (!str)
		return (NULL);
	fresh_str = ft_strdup(str);
	check_malloc(mini, fresh_str);
	return (fresh_str);
}
