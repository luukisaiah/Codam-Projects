/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strnstr.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/15 15:45:11 by lderks         #+#    #+#                */
/*   Updated: 2024/10/22 16:24:13 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	needle_len = (ft_strlen(needle));
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (len > i && haystack[i] != '\0')
	{
		if (needle_len + i > len)
			break ;
		j = 0;
		while (needle_len > j && haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
