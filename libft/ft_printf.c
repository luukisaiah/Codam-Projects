/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:53:10 by doda-cun          #+#    #+#             */
/*   Updated: 2025/01/29 17:56:08 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		arg;

	va_start (arg, format);
	count = 0;
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, arg);
		}
		else
		{
			write(1, &(*format), 1);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
