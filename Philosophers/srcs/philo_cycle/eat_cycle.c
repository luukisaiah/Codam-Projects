/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat_cycle.c                                         :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/30 12:23:04 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/19 14:24:32 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	last_philo_eat_cycle(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken fork");
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken fork");
}

static void	pick_up_fork_left_first(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken a fork");
}

static void	pick_up_fork_right_first(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork");
}

void	eat_cycle(t_philosopher *philo)
{
	if (philo->p_num == philo->num_philo)
		last_philo_eat_cycle(philo);
	else if (philo->p_num % 2 == 0)
		pick_up_fork_left_first(philo);
	else
		pick_up_fork_right_first(philo);
	pthread_mutex_lock(&philo->eat_mutex);
	if (!check_philo_dead(philo))
	{
		philo->last_meal = get_time();
		philo->meal_count++;
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_print(philo, "is eating");
		ft_usleep(philo->tt_eat);
	}
	else
		pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
