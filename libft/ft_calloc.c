/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:04:38 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/24 17:49:23 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > __SIZE_MAX__ / size)
	{
		return (NULL);
	}
	ptr = malloc(count * size);
	if (ptr == 0)
	{
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
