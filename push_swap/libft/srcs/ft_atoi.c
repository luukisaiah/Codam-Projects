/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                           :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 14:06:18 by lderks        #+#    #+#                 */
/*   Updated: 2025/03/17 16:25:36 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == '\t');
}

int	ft_atoi(const char *nbr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if ((*nbr == '-' || *nbr == '+')
			&& (*(nbr + 1) == '-' || *(nbr + 1) == '+'))
			return (0);
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		res = res * 10 + (*nbr - '0');
		nbr++;
	}
	return (res * sign);
}
