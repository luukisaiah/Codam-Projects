/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:10 by doda-cun          #+#    #+#             */
/*   Updated: 2025/01/29 17:06:01 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_signed_decimal(int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
		count += print_signed_decimal(n);
	}
	else if (n > 9)
	{
		count += print_signed_decimal(n / 10);
		count += print_signed_decimal(n % 10);
	}
	else
	{
		digit = n + 48;
		count += write(1, &digit, 1);
	}
	return (count);
}
