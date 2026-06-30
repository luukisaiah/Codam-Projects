/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                          :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 14:50:51 by lderks        #+#    #+#                 */
/*   Updated: 2024/11/18 15:22:00 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
