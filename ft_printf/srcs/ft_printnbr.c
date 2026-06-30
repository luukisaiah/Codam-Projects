/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printnbr.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/12 11:39:24 by lderks         #+#    #+#                */
/*   Updated: 2024/11/18 17:03:17 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printnbr(int c)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(c);
	len = ft_printstring(str);
	free (str);
	return (len);
}
