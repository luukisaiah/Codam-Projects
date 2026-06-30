/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:05 by doda-cun          #+#    #+#             */
/*   Updated: 2025/01/29 17:06:13 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex_lowercase(unsigned long x)
{
	char	*hex_digits;
	char	buffer[18];
	int		i;
	int		reminder;
	int		count_digits;

	hex_digits = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (x > 0)
	{
		reminder = x % 16;
		buffer[i++] = hex_digits[reminder];
		x /= 16;
	}
	count_digits = i;
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
	}
	return (count_digits);
}
