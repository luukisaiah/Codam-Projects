/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex_utils.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/01/21 15:03:55 by lderks         #+#    #+#                */
/*   Updated: 2025/02/11 13:17:28 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}

void	error_exit(int message)
{
	if (message == 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (message == 1)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		ft_putstr_fd("./pipex file1 \"cmd1\" \"cmd2\" file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	is_empty_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

void	extra_check_file(char *file)
{
	if (access (file, F_OK) == -1)
	{
		ft_putstr_fd("Error: no such file or directory: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	if (access (file, R_OK) == -1)
	{
		ft_putstr_fd("Error: permission denied: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
