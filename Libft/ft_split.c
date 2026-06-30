/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_split.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/24 11:49:18 by lderks         #+#    #+#                */
/*   Updated: 2024/10/25 12:32:13 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *str, char c);
static int			subs_length(char const *str, char c);
static char const	*add_substring(char **res, char const *s, char c, int i);
char				**ft_split(char const *s, char c);
static void			free_split(char **split);

static int	word_count(char const *str, char c)
{
	int		on_off;
	int		i;
	int		words;

	i = 0;
	on_off = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && on_off == 0)
		{
			on_off = 1;
			words++;
		}
		else if (str[i] == c)
			on_off = 0;
		i++;
	}
	return (words);
}

static int	subs_length(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char const	*add_substring(char **res, char const *s, char c, int i)
{
	int	len;
	int	j;

	j = 0;
	len = subs_length(s, c);
	res[i] = (char *)malloc((len + 1) * sizeof(char));
	if (!res[i])
	{
		free_split(res);
		return (NULL);
	}
	while (s[j] != '\0' && j < len)
	{
		res[i][j] = s[j];
		j++;
	}
	res[i][len] = '\0';
	s = s + len;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		subs_count;
	int		i;
	char	**res;

	i = 0;
	subs_count = word_count(s, c);
	res = (char **)malloc ((subs_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		s = add_substring(res, s, c, i);
		if (!s)
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free (split);
}
/*
int main() {
    char **result;
    char str[] = "Okaaaaay, i'm reloading     pow pow pow";
    char delimiter = ' ';
    int	i = 0;
    result = ft_split(str, delimiter);
    if (!result) 
	{
        printf("Memory allocation failed!\n");
        return (1);
    }
    while (result[i] != NULL) 
	{
        printf("Substring %d: %s\n", i, result[i]);
        i++;
    }
    free_split(result);
    return (0);
}
*/
