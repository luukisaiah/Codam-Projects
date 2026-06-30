/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleep_cycle.c                                       :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/30 12:22:25 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:22:47 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_cycle(t_philosopher *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->tt_sleep);
}
