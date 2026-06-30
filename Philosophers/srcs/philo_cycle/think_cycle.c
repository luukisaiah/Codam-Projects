/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   think_cycle.c                                       :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 16:33:01 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:24:18 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_cycle(t_philosopher *philo)
{
	int	delay;
	int	elapsed;
	int	max;

	if (check_philo_dead(philo))
		return ;
	ft_print(philo, "is thinking");
	pthread_mutex_lock(&philo->eat_mutex);
	elapsed = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->eat_mutex);
	max = (philo->tt_die - philo->tt_eat) * 0.2;
	delay = max * (1.0 - (elapsed / (float) philo->tt_die));
	if (delay < 1)
		delay = 1;
	ft_usleep(delay);
}
