/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/03 18:20:01 by lderks         #+#    #+#                */
/*   Updated: 2025/04/29 13:10:34 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_fix_buffer(char *buffer, char *read_buffer)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, read_buffer);
	free(buffer);
	return (tmp);
}
/*char	*ft_strchr(const char *s, const char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i_1;
	size_t	i_2;
	char	*s3;

	i_1 = 0;
	i_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[i_1] != '\0')
	{
		s3[i_1] = s1[i_1];
		i_1++;
	}
	while (s2[i_2] != '\0')
	{
		s3[i_1 + i_2] = s2[i_2];
		i_2++;
	}
	s3[i_1 + i_2] = '\0';
	return (s3);
}*/
