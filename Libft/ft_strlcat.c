/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strlcat.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/15 18:47:54 by lderks         #+#    #+#                */
/*   Updated: 2024/10/22 16:11:54 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dst_size)
		dst_len = dst_size;
	if (dst_len == dst_size)
		return (src_len + dst_len);
	if (src_len < dst_size - dst_len)
	{
		ft_memcpy(dst + dst_len, src, src_len + 1);
	}
	else
	{
		ft_memcpy(dst + dst_len, src, dst_size - dst_len - 1);
		dst[dst_size - 1] = '\0';
	}
	return (src_len + dst_len);
}
