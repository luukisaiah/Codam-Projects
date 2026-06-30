/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input_whitespace.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/20 18:48:57 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 17:06:09 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_input_whitespace(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!ft_isspace(input[i]))
			return (0);
		i++;
	}
	return (1);
}
