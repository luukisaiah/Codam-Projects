/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printhex.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 12:50:49 by lderks         #+#    #+#                */
/*   Updated: 2024/12/05 14:58:15 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hex_convert(unsigned int hex, char *buffer, const char format_s)
{
	int	nb;
	int	i;

	i = 0;
	if (hex == 0)
	{
		buffer[0] = '0';
		return (1);
	}
	while (hex != 0)
	{
		nb = hex % 16;
		if (nb <= 9)
			buffer[i++] = nb + '0';
		else
		{
			if (format_s == 'x')
				buffer[i++] = (nb - 10 + 'a');
			else if (format_s == 'X')
				buffer[i++] = (nb - 10 + 'A');
		}
		hex = hex / 16;
	}
	buffer[i] = 0;
	return (i);
}

int	ft_printhex(unsigned int hex, const char format_s)
{
	int		len;
	char	buffer[32];
	int		written;
	int		total;

	ft_bzero(buffer, 32);
	total = 0;
	len = hex_convert(hex, buffer, format_s);
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
