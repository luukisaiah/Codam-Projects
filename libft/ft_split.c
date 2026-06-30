/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:10:18 by doda-cun          #+#    #+#             */
/*   Updated: 2025/07/07 19:44:16 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	word_count(char const *s, char delimiter);
static char			*word_malloc(const char *s, int start, int end);
static void			*ft_free(char **str, int count);
static void			ft_variable_initializer(size_t *i, int *j, int *start);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	int		j;
	int		start;

	ft_variable_initializer(&i, &j, &start);
	split = malloc ((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j] = word_malloc (s, start, i);
			if (!split[j])
				return (ft_free(split, j));
			j++;
			start = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

static void	ft_variable_initializer(size_t *i, int *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

static unsigned int	word_count(char const *s, char delimiter)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimiter && in_word == 0)
		{
			in_word = 1;
			words ++;
		}
		else if (*s == delimiter)
		{
			in_word = 0;
		}
		s++;
	}
	return (words);
}

static char	*word_malloc(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc ((end - start + 1) * sizeof(char));
	i = 0;
	if (!word)
	{
		return (NULL);
	}
	while (start < end)
	{
		word[i++] = s[start++];
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
