/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isalnum.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 12:38:25 by lderks         #+#    #+#                */
/*   Updated: 2024/10/17 16:21:56 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if ((alnum >= '0' && alnum <= '9')
		|| (alnum >= 'A' && alnum <= 'Z')
		|| (alnum >= 'a' && alnum <= 'z'))
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
	char test;

	test = 'i';

	if (ft_isalnum(test))
	{
		printf("This is a number or letter bro, IT IS %c. \n", test);
	}
	else
	{
		printf("DUMB, check it out yo-self: %c. \n", test);
	}
}
*/
