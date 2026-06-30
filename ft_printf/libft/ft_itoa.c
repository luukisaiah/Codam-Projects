/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 15:23:06 by lderks        #+#    #+#                 */
/*   Updated: 2024/11/18 15:21:36 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

static int	nb_len(int n, int *sign)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		*sign = -1;
		if (n == INT_MIN)
			return (11);
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	convert_to_string(char *res, int n, int len)
{
	while (n != 0)
	{
		res[len] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	sign = 1;
	if (n == 0)
		return (allocate_zero());
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = nb_len(n, &sign);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (sign < 0)
	{
		res[0] = '-';
		n = -n;
	}
	len--;
	convert_to_string(res, n, len);
	return (res);
}
