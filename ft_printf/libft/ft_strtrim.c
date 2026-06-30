/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 12:42:23 by lderks        #+#    #+#                 */
/*   Updated: 2024/11/18 15:23:54 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_trim_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	char	*new_str;
	size_t	new_str_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_trim_set(s1[i], set))
		i++;
	while (s1_len > i && ft_trim_set(s1[s1_len - 1], set))
		s1_len--;
	new_str_len = s1_len - i;
	new_str = malloc((new_str_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < new_str_len)
	{
		new_str[j] = s1[i + j];
		j++;
	}
	new_str[new_str_len] = '\0';
	return (new_str);
}
