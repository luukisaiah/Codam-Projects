/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:05:49 by doda-cun          #+#    #+#             */
/*   Updated: 2025/01/29 17:06:16 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(arg, int));
	else if (specifier == 's')
		count += print_str(va_arg(arg, char *));
	else if (specifier == 'p')
		count += print_ptr(va_arg(arg, void *));
	else if (specifier == 'd')
		count += print_signed_decimal(va_arg(arg, int));
	else if (specifier == 'i')
		count += print_signed_decimal(va_arg(arg, int));
	else if (specifier == 'u')
		count += print_unsigned_decimal(va_arg(arg, unsigned int));
	else if (specifier == 'x')
		count += print_hex_lowercase(va_arg(arg, unsigned int));
	else if (specifier == 'X')
		count += print_hex_uppercase (va_arg(arg, unsigned int));
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}
