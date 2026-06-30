/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:45:05 by doda-cun          #+#    #+#             */
/*   Updated: 2024/10/24 16:01:03 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int nbr);

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (--len >= (n < 0))
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

static int	int_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		len++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
