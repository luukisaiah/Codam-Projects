/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                       :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 12:52:04 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:31:28 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		return (0);
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_number_range(char *arg, int j)
{
	int	num;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (arg[i] == ' ' || arg[i] == '+' || arg[i] == '-' || arg[i] == '0')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		len++;
		i++;
	}
	if (len > 10)
		return (0);
	num = ft_atoi(arg);
	if (num <= 0 || num > INT_MAX || (num > MAX_PHILO && j == 1))
		return (0);
	return (1);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: Invalid Number of Arguments\n", 35);
		return (0);
	}
	if (argv[1][0] == '0' && argv[1][1] == '\0')
		return (write(2, "Error: Minimum of 1 Philosopher\n", 32), 0);
	while (i < argc)
	{
		if (!check_number(argv[i]))
		{
			write(2, "Error: All Arguments must be Numbers\n", 37);
			return (0);
		}
		if (!check_number_range(argv[i], i))
		{
			write(2, "Error: Argument out of range\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}
