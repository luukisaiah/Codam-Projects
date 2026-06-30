/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 11:44:06 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/11/11 18:46:51 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *result)
{
	char	*stash;
	int		bytes_read;

	stash = malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (free(result), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (stash);
			free (result);
			return (NULL);
		}
		stash[bytes_read] = '\0';
		result = ft_joinfree(result, stash);
		if (ft_strchr(stash, '\n') || !result)
			break ;
	}
	free(stash);
	return (result);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	len;
	size_t	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	len = i + 1;
	if (stash[i] == '\n')
		len++;
	line = (char *)malloc(len);
	if (!line)
		return (NULL);
	i = 0;
	while (stash [i] && stash [i] != '\n')
	{
		line[i] = stash [i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*remove_extracted_line(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	if (stash[i + 1] == '\0')
	{
		free (stash);
		return (NULL);
	}
	new_stash = ft_strjoin("", stash + i + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free (stash);
	return (new_stash);
}

static char	*stash_initialized(char *stash)
{
	if (stash)
		return (stash);
	stash = malloc(1);
	if (!stash)
		return (NULL);
	stash[0] = 0;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0)
		return (ft_freestash(stash));
	if (BUFFER_SIZE <= 0)
		return (NULL);
	stash = stash_initialized(stash);
	if (!stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
	{
		stash = read_file(fd, stash);
		if (!stash)
			return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = remove_extracted_line(stash);
	return (line);
}
