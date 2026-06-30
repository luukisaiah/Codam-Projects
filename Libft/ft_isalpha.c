/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isalpha.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 12:38:39 by lderks         #+#    #+#                */
/*   Updated: 2024/10/18 12:37:22 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int alpha)
{
	if ((alpha >= 'A' && alpha <= 'Z') || (alpha >= 'a' && alpha <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
