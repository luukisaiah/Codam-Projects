/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_cycle.c                                       :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/18 14:47:34 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:23:31 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_single_cycle(t_philosopher *philo)
{
	ft_print(philo, "has taken a fork");
	ft_usleep(philo->tt_die);
	ft_print(philo, "died");
	pthread_mutex_lock(philo->dead_mutex);
	*(philo->is_dead) = 1;
	pthread_mutex_unlock(philo->dead_mutex);
	return (NULL);
}

void	*philo_cycle(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_time() + philo->num_philo;
	pthread_mutex_unlock(&philo->eat_mutex);
	harmonize_philos_start(philo->start_time + 10);
	if (philo->num_philo == 1)
		return (philo_single_cycle(philo));
	if (philo->p_num % 2 == 0)
		ft_usleep(2);
	while (check_philo_dead(philo) == 0)
	{
		eat_cycle(philo);
		sleep_cycle(philo);
		think_cycle(philo);
	}
	return (NULL);
}
