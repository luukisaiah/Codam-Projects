/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:48:03 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 20:13:15 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*substr_safe(t_minishell *shell, char const *s,
	unsigned int start, size_t len)
{
	char	*fresh_str;

	fresh_str = ft_substr(s, start, len);
	check_malloc(shell, fresh_str);
	return (fresh_str);
}
