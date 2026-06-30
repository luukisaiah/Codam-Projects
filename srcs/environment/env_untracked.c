/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_untracked.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:38:30 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:26:16 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array_untracked(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**copy_string_arr(char **arr)
{
	int		i;
	char	**copy;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		copy[i] = ft_strdup(arr[i]);
		if (!copy[i])
		{
			free_array_untracked(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	**env_list_to_envp_untracked(t_env *env_list)
{
	char	**envp;
	t_env	*current;
	int		i;
	int		count;

	count = 0;
	current = env_list;
	while (current && ++count)
		current = current->next;
	envp = malloc(sizeof(char *) * (count + 1));
	if (!envp)
		return (NULL);
	current = env_list;
	i = 0;
	while (current)
	{
		envp[i] = create_env_string(current);
		if (!envp[i])
			return (free_envp(envp, i), NULL);
		i++;
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	free_env_untracked(t_env *env_list)
{
	t_env	*current;
	t_env	*next;

	current = env_list;
	while (current)
	{
		next = current->next;
		if (current->name)
			free(current->name);
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
}
