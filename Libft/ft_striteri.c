/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_striteri.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/24 11:50:20 by lderks         #+#    #+#                */
/*   Updated: 2024/10/24 12:15:29 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
