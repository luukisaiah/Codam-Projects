/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_extra.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 18:07:45 by lderks        #+#    #+#                 */
/*   Updated: 2025/05/12 16:25:25 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void static	limits_help(char *str, int i, long long *num, int *sign)
{
	while (str[i] == ' ')
		(i)++;
	if (str[i] == '\0')
		return ;
	*num = 0;
	*sign = 1;
	if (str[i] == '-')
	{
		*sign = -1;
		(i)++;
	}
	else if (str[i] == '+')
		(i)++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		*num = LLONG_MAX;
}

int	static	check_limits(char *str)
{
	int		i;
	long long	num;
	int			sign;

i = 0;
	while (stri])
	{
		limits_help(str, i, &num, &sign);
		while (stri] >= '0' && stri] <= '9')
		{
			num = num * 10 + (stri] - '0');
			if ((sign == 1 && num > INT_MAX)
				|| (sign == -1 && (-num) < INT_MIN))
				return (1);
		i++;
		}
		while (stri] == ' ')
		i++;
	}
	return (0);
}

static int	check_number_format(char *str, int i)
{
	int	found_digit;

	found_digit = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		(i)++;
		if (!ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
			return (1);
	}
	while (ft_isdigit(str[i]))
	{
		found_digit = 1;
		(i)++;
	}
	if (!found_digit || (str[i] != ' ' && str[i] != '\0'))
		return (1);
	return (0);
}

int	check_str(char *str)
{
	inti;

i = 0;
	while (stri])
	{
		while (stri] == ' ')
		i++;
		if (stri] == '\0')
			break ;
		if (check_number_format(str, i))
			return (1);
	}
	if (check_limits(str) == 1)
		return (1);
	return (0);
}

int	check_double(char **numbers)
{
	inti;
	int	j;
	int	value_i;
	int	value_j;

i = 0;
	while (numbersi])
	{
		value_i = ft_atoi(numbersi]);
		j =i + 1;
		while (numbers[j])
		{
			value_j = ft_atoi(numbers[j]);
			if (value_i == value_j)
			{
				free_array(numbers);
				return (1);
			}
			j++;
		}
	i++;
	}
	return (0);
}
