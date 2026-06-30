/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/24 11:50:39 by lderks        #+#    #+#                 */
/*   Updated: 2025/03/17 16:20:41 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
