/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isdigit.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 12:38:58 by lderks         #+#    #+#                */
/*   Updated: 2025/11/14 13:49:32 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int digit)
{
	if (digit >= '0' && digit <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
