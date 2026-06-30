/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:39:45 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/22 19:10:10 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && to_trim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && to_trim(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed_str = (char *)malloc((len +1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, &s1[start], len + 1);
	return (trimmed_str);
}

static int	to_trim(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
