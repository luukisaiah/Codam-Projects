/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:39:05 by doda-cun          #+#    #+#             */
/*   Updated: 2025/07/03 16:57:08 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	size_t			len;
	char			*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!(str))
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
