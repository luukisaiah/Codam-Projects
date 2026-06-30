/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 13:56:48 by lderks        #+#    #+#                 */
/*   Updated: 2025/03/17 16:20:30 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*pointer;

	pointer = ptr;
	while (len > 0)
	{
		*pointer = (unsigned char) c;
		pointer++;
		len--;
	}
	return (ptr);
}
