/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:34:08 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:12:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strjoin_safe(t_minishell *shell, char const *s1, char const *s2)
{
	char	*fresh_str;

	if (!s1 || !s2)
		return (NULL);
	fresh_str = ft_strjoin(s1, s2);
	check_malloc(shell, fresh_str);
	return (fresh_str);
}
