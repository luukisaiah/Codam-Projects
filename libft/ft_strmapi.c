/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:32 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/23 18:50:29 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*modified;
	unsigned int	i;

	if (!s || !f)
	{
		return (NULL);
	}
	modified = (char *)malloc(sizeof(char) * (ft_strlen(s)+1));
	if (!modified)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		modified[i] = f(i, s[i]);
		i++;
	}
	modified[i] = '\0';
	return (modified);
}

/*char	capitalize_odd(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		return ((char)ft_tolower(c));
	}
	else
		return ((char)ft_toupper(c));
}

#include <stdlib.h>

int	main(void)
{
	char *s = "Hello my name is milla";
	char *new = ft_strmapi(s, capitalize_odd);
	if(new)
	{
		printf ("%s\n", new);
		free(new);
	}
	 else
    {
        printf("Memory allocation failed or input string is NULL\n");
    }
	return(0);

}*/
