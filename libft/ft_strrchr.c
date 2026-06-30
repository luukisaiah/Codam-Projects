/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:11:09 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/24 18:53:07 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurance;

	last_occurance = (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			last_occurance = (char *)s;
		}
		s++;
	}
	if (*s == (char) c)
	{
		return ((char *) s);
	}
	return (last_occurance);
}

// int	main(void)
// {
// 	char *a = "\0";
// 	printf("%p\n", ft_strrchr(a, '\0'));
// }
