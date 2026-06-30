/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:23 by doda-cun          #+#    #+#             */
/*   Updated: 2025/01/29 17:05:31 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned_decimal(unsigned int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += print_unsigned_decimal(n / 10);
		count += print_unsigned_decimal(n % 10);
	}
	else
	{
		digit = n + 48;
		count += write (1, &digit, 1);
	}
	return (count);
}
