/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:52:01 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/23 17:49:36 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *) malloc((len + 1) * sizeof(char));
	if (!new_str)
	{
		return (NULL);
	}
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, s2, len + 1);
	return (new_str);
}
