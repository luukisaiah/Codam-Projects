/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 20:32:18 by lderks        #+#    #+#                 */
/*   Updated: 2024/11/18 15:21:49 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	count;
	size_t			i;

	str = (unsigned char *)s;
	count = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == count)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
