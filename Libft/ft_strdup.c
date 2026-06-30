/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/15 18:48:50 by lderks         #+#    #+#                */
/*   Updated: 2024/10/18 12:45:56 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	duplicate = malloc((s_len + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (s[i])
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = 0;
	return (duplicate);
}
