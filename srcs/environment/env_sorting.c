/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:01:02 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 12:02:16 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	**env_list_to_array(t_minishell *shell, t_env *head, int *size)
{
	t_env	*tmp;
	int		node_count;
	t_env	**arr;
	int		i;

	node_count = 0;
	tmp = head;
	while (tmp)
	{
		node_count++;
		tmp = tmp->next;
	}
	arr = safe_malloc(shell, sizeof(t_env *) * node_count);
	if (!arr)
		return (NULL);
	tmp = head;
	i = 0 ;
	while (i < node_count)
	{
		arr[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	*size = node_count;
	return (arr);
}

void	sort_env_arr(t_env **env_arr, int size)
{
	t_env	*tmp;
	int		i;
	int		swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(env_arr[i]->name, env_arr[i + 1]->name) > 0)
			{
				tmp = env_arr[i];
				env_arr[i] = env_arr[i + 1];
				env_arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
}

void	print_sorted_env(t_minishell *shell, t_env *head)
{
	int		size;
	t_env	**env_arr;
	int		i;

	i = 0;
	env_arr = env_list_to_array(shell, head, &size);
	if (!env_arr)
		return ;
	sort_env_arr(env_arr, size);
	while (i < size)
	{
		if (env_arr[i]->value)
			printf("declare -x %s=\"%s\"\n", env_arr[i]->name,
				env_arr[i]->value);
		else
			printf("declare -x %s\n", env_arr[i]->name);
		i++;
	}
	safe_free(shell, (void **)&env_arr);
}

int	env_list_size(t_env *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
