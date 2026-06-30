/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safe_malloc.c                                       :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/09 13:11:52 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 13:20:15 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*safe_malloc(t_minishell *mini, size_t size)
{
	void	*ptr;

	if (size == 0)
	{
		error_message("malloc", "attempted zero-size allocation");
		cleanup_and_exit(mini);
	}
	ptr = malloc(size);
	check_malloc(mini, ptr);
	return (ptr);
}
