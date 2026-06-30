/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 11:44:09 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/11/11 19:30:25 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *result, char *join)
{
	char	*temp;

	temp = ft_strjoin(result, join);
	free(result);
	return (temp);
}

char	*ft_freestash(char *stash)
{
	if (stash)
	{
		free(stash);
		stash = NULL;
	}
	return (NULL);
}
