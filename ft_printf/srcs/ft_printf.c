/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 16:26:11 by lderks         #+#    #+#                */
/*   Updated: 2025/01/14 19:17:55 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printpercent(void)
{
	return (write(1, "%", 1));
}

int	ft_format(va_list args, const char format_s)
{
	int	len;

	len = 0;
	if (format_s == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (format_s == 's')
		len = ft_printstring(va_arg(args, char *));
	else if (format_s == 'p')
		len += ft_printpointer(va_arg(args, unsigned long long));
	else if (format_s == 'd' || format_s == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format_s == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	else if (format_s == 'x' || format_s == 'X')
		len += ft_printhex(va_arg(args, unsigned int), format_s);
	else if (format_s == '%')
		len += ft_printpercent();
	else
		return (-1);
	if (len < 0)
		return (-1);
	return (len);
}

static void	process_str(const char *str, va_list args, int *i, int *len)
{
	int	res;

	if (str[*i] == '%')
	{
		res = ft_format(args, str[*i + 1]);
		if (res < 0)
		{
			*len = -1;
			return ;
		}
		*len += res;
		(*i)++;
	}
	else
	{
		if (write(1, &str[*i], 1) == -1)
		{
			*len = -1;
			return ;
		}
		(*len)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] && len >= 0)
	{
		process_str(str, args, &i, &len);
		i++;
	}
	va_end(args);
	return (len);
}
