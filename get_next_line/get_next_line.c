/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 18:22:44 by lderks        #+#    #+#                 */
/*   Updated: 2025/01/13 13:19:14 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_and_fill_buffer(int fd, char *buffer);
static char	*find_line_in_buffer(char *buffer);
static char	*clean_buffer(char *buffer);
static char	*initialize_buffer(char *buffer);
char		*get_next_line(int fd);

static char	*read_and_fill_buffer(int fd, char *buffer)
{
	ssize_t	have_read;
	char	*read_buffer;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (free(buffer), NULL);
	have_read = 1;
	while (have_read > 0)
	{
		have_read = read(fd, read_buffer, BUFFER_SIZE);
		if (have_read < 0)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		read_buffer[have_read] = 0;
		buffer = ft_fix_buffer(buffer, read_buffer);
		if (!buffer || ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (buffer);
}

static char	*find_line_in_buffer(char *buffer)
{
	int		i;
	char	*result;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = malloc(i + 1 + (buffer[i] == '\n'));
	if (!result)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer [i] != '\n')
	{
		result [i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		result[i++] = '\n';
	result[i] = 0;
	return (result);
}

static char	*clean_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(ft_strlen(buffer) - i + 1);
	if (!line)
	{
		return (free(buffer), NULL);
	}
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = 0;
	free (buffer);
	return (line);
}

static char	*initialize_buffer(char *buffer)
{
	if (buffer)
		return (buffer);
	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = initialize_buffer(buffer);
	if (!buffer)
		return (NULL);
	buffer = read_and_fill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = find_line_in_buffer(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = clean_buffer(buffer);
	return (line);
}
