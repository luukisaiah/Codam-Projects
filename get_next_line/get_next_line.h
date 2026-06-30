/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/03 15:51:19 by lderks         #+#    #+#                */
/*   Updated: 2024/12/19 17:51:20 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, const char c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_fix_buffer(char *buffer, char *read_buffer);

#endif
