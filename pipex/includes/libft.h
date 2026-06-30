/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   libft.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/17 18:09:19 by lderks         #+#    #+#                */
/*   Updated: 2025/02/06 17:49:07 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif
