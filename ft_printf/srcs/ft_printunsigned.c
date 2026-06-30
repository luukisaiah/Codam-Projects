/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printunsigned.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/12 15:06:50 by lderks         #+#    #+#                */
/*   Updated: 2024/12/05 14:57:26 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	nb_len(unsigned int c)
{
	int	len;

	len = 0;
	while (c != 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

static char	*allocate_zero(void)
{
	char	*res;

	res = (char *)malloc(2 * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static char	*unsigned_itoa(unsigned int c)
{
	char	*res;
	int		len;

	if (c == 0)
		return (allocate_zero());
	len = nb_len(c);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	while (c != 0)
	{
		res[len] = (c % 10) + '0';
		len--;
		c = c / 10;
	}
	return (res);
}

static int	ft_unsigned_printstring(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(string is NULL)", 16);
		return (16);
	}
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_printunsigned(unsigned int c)
{
	char	*res;
	int		len;

	res = unsigned_itoa(c);
	len = ft_unsigned_printstring(res);
	free (res);
	return (len);
}
