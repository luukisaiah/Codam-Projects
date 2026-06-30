/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memset.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 13:56:48 by lderks         #+#    #+#                */
/*   Updated: 2024/10/22 16:14:20 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
