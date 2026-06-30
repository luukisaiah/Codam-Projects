/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printstring.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/12 11:10:08 by lderks         #+#    #+#                */
/*   Updated: 2024/11/26 18:53:32 by lderks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printstring(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
		i++;
	return (write(1, str, i));
}
