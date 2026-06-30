/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/11 15:01:04 by lderks         #+#    #+#                */
/*   Updated: 2024/11/14 18:27:24 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_printstring(char *str);
int	ft_printpointer(unsigned long long ptr);
int	ft_printnbr(int c);
int	ft_printunsigned(unsigned int c);
int	ft_printhex(unsigned int hex, const char format_s);
#endif
