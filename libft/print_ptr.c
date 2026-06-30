/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:15 by doda-cun          #+#    #+#             */
/*   Updated: 2025/01/29 17:06:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long) ptr;
	count = 0;
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	count += write(1, "0x", 2);
	count += print_hex_lowercase(addr);
	return (count);
}
