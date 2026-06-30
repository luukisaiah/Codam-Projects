/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:57:40 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/23 17:49:40 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t destsize)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= destsize)
	{
		dest_len = destsize;
	}
	if (dest_len == destsize)
	{
		return (destsize + src_len);
	}
	if (src_len < destsize - dest_len)
	{
		ft_memcpy(dest + dest_len, src, src_len +1);
	}
	else
	{
		ft_memcpy(dest + dest_len, src, destsize - dest_len -1);
		dest[destsize - 1] = '\0';
	}
	return (dest_len + src_len);
}
