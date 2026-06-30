/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:16:20 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/14 18:47:28 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cs;

	cs = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cs)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == cs)
	{
		return ((char *) &s[i]);
	}
	return ((void *)0);
}
