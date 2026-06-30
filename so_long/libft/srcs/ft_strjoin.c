/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 12:04:03 by lderks        #+#    #+#                 */
/*   Updated: 2025/03/17 16:20:58 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i_1;
	size_t	i_2;
	char	*s3;

	i_1 = 0;
	i_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
}
