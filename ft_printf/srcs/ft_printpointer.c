/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printpointer.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/12 17:18:39 by lderks         #+#    #+#                */
/*   Updated: 2024/12/05 15:01:39 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	pointer_convert(unsigned long long hex, char *buf, const char f_s)
{
	int	nb;
	int	i;

	i = 0;
	if (hex == 0)
	{
		buf[0] = '0';
		return (1);
	}
	while (hex != 0)
	{
		nb = hex % 16;
		if (nb <= 9)
			buf[i++] = nb + '0';
		else
		{
			if (f_s == 'x')
				buf[i++] = (nb - 10 + 'a');
			else if (f_s == 'X')
				buf[i++] = (nb - 10 + 'A');
		}
		hex = hex / 16;
	}
	buf[i] = 0;
	return (i);
}

static int	ft_writepointer(unsigned long long hex, const char format_s)
{
	int		len;
	char	buffer[32];
	int		written;
	int		total;

	ft_bzero(buffer, 32);
	total = 0;
	len = pointer_convert(hex, buffer, format_s);
	while (len > 0)
	{
		written = write(1, &buffer[len - 1], 1);
		if (written == -1)
			return (-1);
		total++;
		len--;
	}
	return (total);
}

int	ft_printpointer(unsigned long long ptr)
{
	int			len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = 2;
	if (ptr == 0)
		return (write(1, "0", 1));
	len += ft_writepointer(ptr, 'x');
	return (len);
}
