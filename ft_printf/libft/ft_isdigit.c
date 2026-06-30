/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 12:38:58 by lderks        #+#    #+#                 */
/*   Updated: 2024/11/18 15:21:51 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
/*
int main(void)
{
	unsigned char a;
	
	a = 't';
	if (ft_isdigit(a))
	{
		printf("The digit is: %c. \n", a);
	}
	else
	{
		printf("This ain't no digit yo, this a %c. \n", a);
	}
	return (0);
}
*/
