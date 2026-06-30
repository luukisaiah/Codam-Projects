/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_nbr.c                                         :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 13:46:51 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:19:56 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] == '+' || str[i + 1] == '-'))
			return (0);
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit((unsigned char)str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
