/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_error_forks.c                                :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/18 14:11:40 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:31:57 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error_forks(pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
