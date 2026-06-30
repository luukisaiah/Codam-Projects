/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 14:12:30 by lderks        #+#    #+#                 */
/*   Updated: 2025/03/17 16:21:26 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

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
