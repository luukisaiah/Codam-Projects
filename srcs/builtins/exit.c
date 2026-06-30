/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 13:26:56 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/07 13:12:28 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_numeric(char *args);
static int	is_out_of_range(const char *str);

int	builtin_exit(t_minishell *shell, char **args)
{
	printf("exit\n");
	if (!args[1])
	{
		shell->should_exit = 1;
		shell->exit_status = 0;
		return (0);
	}
	if (!is_numeric(args[1]) || is_out_of_range(args[1]))
	{
		shell->should_exit = 1;
		shell->exit_status = 2;
		write(2, "exit: ", 6);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		return (2);
	}
	if (args[2])
	{
		write(2, "exit\n", 5);
		write(2, "exit: too many arguments\n", 25);
		return (1);
	}
	shell->exit_status = ft_atoi(args[1]) % 256;
	shell->should_exit = 1;
	return (shell->exit_status);
}

int	is_numeric(char *args)
{
	int	i;

	i = 0 ;
	if (args[0] == '-' || args[0] == '+')
		i++;
	while (args[i])
	{
		if (!ft_isdigit(args[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_out_of_range(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > 2147483648LL))
			return (1);
		i++;
	}
	return (0);
}
