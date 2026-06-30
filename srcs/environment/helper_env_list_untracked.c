/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_env_list_untracked.c                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:14:46 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/11 13:12:20 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_env_string(t_env *node)
{
	char	*str;
	int		len;

	len = ft_strlen(node->name) + ft_strlen(node->value) + 2;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, node->name, len);
	ft_strlcat(str, "=", len);
	ft_strlcat(str, node->value, len);
	return (str);
}

char	**free_envp(char **envp, int i)
{
	while (--i >= 0)
		free(envp[i]);
	free(envp);
	return (NULL);
}
