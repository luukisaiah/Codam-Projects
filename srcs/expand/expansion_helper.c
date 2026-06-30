/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion_helper.c                                  :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/30 17:20:58 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/02 20:06:57 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_special_dollar(t_minishell *shell, char c, int *i)
{
	char	*value;
	char	*temp;

	(*i)++;
	if (c == '?')
		temp = ft_itoa(shell->last_exit_status);
	else
		temp = ft_itoa(getpid());
	value = strdup_safe(shell, temp);
	free(temp);
	return (value);
}

char	*handle_dollar_expansion(t_minishell *shell, char *arg,
			int *i, t_env *env_list)
{
	char	*varname;
	char	*value;

	(*i)++;
	if (arg[*i] == '\0')
		return (strdup_safe(shell, "$"));
	if (arg[*i] == '?' || arg[*i] == '$')
		return (handle_special_dollar(shell, arg[*i], i));
	if (ft_isalpha(arg[*i]) || arg[*i] == '_')
	{
		varname = extract_varname(shell, arg, i);
		value = get_env_value(shell, env_list, varname);
		safe_free(shell, (void **)&varname);
		if (value)
			return (strdup_safe(shell, value));
		return (strdup_safe(shell, ""));
	}
	(*i)++;
	return (strdup_safe(shell, "$"));
}

char	*extract_varname(t_minishell *mini, const char *s, int *i)
{
	int	start;

	start = *i;
	while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_'))
		(*i)++;
	return (substr_safe(mini, s, start, *i - start));
}

char	**expand_variables(t_minishell *mini, char **args, t_env *env_list)
{
	int		i;
	char	*expanded;

	i = 0;
	while (args[i])
	{
		expanded = expand_one_arg(mini, args[i], env_list);
		safe_free(mini, (void **)&args[i]);
		args[i] = expanded;
		i++;
	}
	return (args);
}

char	*expand_tilde(char *path, t_env *env_list, t_minishell *shell)
{
	char	*home;
	char	*expanded;

	if (!path || path[0] != '~')
		return (path);
	home = get_env_value(shell, env_list, "HOME");
	if (!home)
		return (NULL);
	if (path[1] == '\0')
		return (strdup_safe(shell, home));
	if (path[1] == '/')
	{
		expanded = ft_strjoin(home, &path[1]);
		return (expanded);
	}
	return (path);
}
