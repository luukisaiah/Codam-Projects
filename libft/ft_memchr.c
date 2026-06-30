/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:00:38 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/22 18:59:52 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	v;

	str = (unsigned char *)s;
	v = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == v)
		{
			return ((void *) &str[i]);
		}
		i++;
	}
	return ((void *)0);
}
