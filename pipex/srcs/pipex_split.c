/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex_split.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/06 19:11:57 by lderks         #+#    #+#                */
/*   Updated: 2025/02/10 15:29:12 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	count_tokens(char *cmd)
{
	int		t_count;
	int		i;
	int		in_quotes;
	char	quote_char;

	t_count = 0;
	i = 0;
	in_quotes = 0;
	quote_char = 0;
	while (cmd[i])
	{
		while (cmd[i] && ft_isspace(cmd[i]))
			i++;
		if (cmd[i])
		{
			t_count++;
			while (cmd[i] && (in_quotes || !ft_isspace(cmd[i])))
			{
				in_quotes = handle_quotes(cmd[i], in_quotes, &quote_char);
				i++;
			}
		}
	}
	return (t_count);
}

static char	*extract_token(char *cmd, int *start)
{
	int		i;
	int		token_start;
	int		in_quotes;
	char	quote_char;

	i = *start;
	token_start = i;
	in_quotes = 0;
	quote_char = 0;
	while (cmd[i] && (in_quotes || !ft_isspace(cmd[i])))
	{
		in_quotes = handle_quotes(cmd[i], in_quotes, &quote_char);
		i++;
	}
	*start = i;
	return (ft_substr(cmd, token_start, i - token_start));
}

static char	*remove_quotes(char *token)
{
	size_t	len;
	char	*new_token;

	if (!token)
		return (NULL);
	len = ft_strlen(token);
	if (len >= 2 && is_quote(token[0]) && token[0] == token[len - 1])
	{
		new_token = ft_substr(token, 1, len - 2);
		free(token);
		return (new_token);
	}
	return (token);
}

static void	*free_and_null(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

char	**pipex_split(char *cmd)
{
	char	**res;
	int		t_count;
	int		i;
	int		now_t;

	initialize_everything(&t_count, &i, &now_t, cmd);
	res = malloc((t_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (now_t < t_count)
	{
		while (cmd[i] && ft_isspace(cmd[i]))
			i++;
		if (cmd[i])
		{
			res[now_t] = extract_token(cmd, &i);
			res[now_t] = remove_quotes(res[now_t]);
			if (!res[now_t])
				free_and_null(res);
			now_t++;
		}
	}
	res[now_t] = NULL;
	return (res);
}
