/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 10:47:52 by lderks        #+#    #+#                 */
/*   Updated: 2024/11/29 19:01:57 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_into_d(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (d > s && d < s + len)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	else
		copy_into_d(d, s, len);
	return (dst);
}
