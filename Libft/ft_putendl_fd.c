/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putendl_fd.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/24 11:50:59 by lderks         #+#    #+#                */
/*   Updated: 2025/03/14 13:11:49 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s);
	ft_putchar_fd("\n");
}
