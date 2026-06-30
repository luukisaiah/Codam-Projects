/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_philo_dead.c                                  :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/21 14:16:27 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:24:48 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_dead(t_philosopher *philo)
{
	int	dead;

	pthread_mutex_lock(philo->dead_mutex);
	dead = *(philo->is_dead);
	pthread_mutex_unlock(philo->dead_mutex);
	return (dead);
}
