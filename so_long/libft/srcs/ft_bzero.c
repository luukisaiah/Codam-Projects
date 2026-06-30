/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_bzero.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 14:50:51 by lderks         #+#    #+#                */
/*   Updated: 2025/03/17 15:59:08 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*tmp;

	tmp = (char *)ptr;
	while (n > 0)
	{
		*tmp = '\0';
		tmp++;
		n--;
	}
}
