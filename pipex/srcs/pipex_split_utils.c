/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex_split_utils.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/04 20:49:53 by lderks         #+#    #+#                */
/*   Updated: 2025/02/11 14:34:51 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	initialize_everything(int *t_count, int *i, int *now_t, char *cmd)
{
	*t_count = count_tokens(cmd);
	*i = 0;
	*now_t = 0;
}

int	handle_quotes(char c, int in_quotes, char *quote_char)
{
	if (!in_quotes && is_quote(c))
	{
		*quote_char = c;
		return (1);
	}
	else if (c == *quote_char)
		return (0);
	return (in_quotes);
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

void	command_not_found(char *command)
{
	ft_putstr_fd("Error: command not found: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
