/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strrchr.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/11 14:12:30 by lderks         #+#    #+#                */
/*   Updated: 2024/10/18 11:48:06 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = ft_strlen(src);
	while (i >= 0)
	{
		if (src[i] == (char)c)
		{
			return ((char *)&src[i]);
		}
		i--;
	}
	return (NULL);
}
