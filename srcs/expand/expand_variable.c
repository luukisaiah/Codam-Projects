/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_variable.c                                   :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/08 18:49:48 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/11/11 19:53:03 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_tilde_at_start(t_minishell *shell,
	char *arg, t_env *env_list)
{
	char	*home;
	char	*result;

	if (arg[0] != '~' || (arg[1] != '\0' && arg[1] != '/'))
		return (NULL);
	home = get_env_value(shell, env_list, "HOME");
	if (!home)
		return (strdup_safe(shell, arg));
	if (arg[1] == '\0')
		return (strdup_safe(shell, home));
	result = strjoin_safe(shell, home, &arg[1]);
	return (result);
}

static char	*append_str(t_minishell *shell, char *result, char *str)
{
	char	*new_result;

	new_result = strjoin_safe(shell, result, str);
	safe_free(shell, (void **)&result);
	return (new_result);
}

static char	*process_char(t_minishell *shell, char *result, char c)
{
	char	temp[2];

	temp[0] = c;
	temp[1] = '\0';
	return (append_str(shell, result, temp));
}

char	*expand_one_arg(t_minishell *shell, char *arg, t_env *env_list)
{
	int		i;
	char	*result;
	char	*tilde_expanded;
	char	*expanded;

	tilde_expanded = handle_tilde_at_start(shell, arg, env_list);
	if (tilde_expanded)
		arg = tilde_expanded;
	i = 0;
	result = strdup_safe(shell, "");
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			expanded = handle_dollar_expansion(shell, arg, &i, env_list);
			result = append_str(shell, result, expanded);
			safe_free(shell, (void **)&expanded);
		}
		else
			result = process_char(shell, result, arg[i++]);
	}
	if (tilde_expanded)
		safe_free(shell, (void **)&tilde_expanded);
	return (result);
}
