/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:22:10 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 22:22:12 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*ph_monitor(void *philo)
{
	int	last_time;
	int current_time;

	while (1)
	{
		if (g_data.if_some_philo_die)
			break ;
		pthread_mutex_lock(&((t_philo *)philo)->eat_time_mutex);
		last_time = ((t_philo *)philo)->last_time_eat;
		current_time = ph_time();
		if((current_time - last_time) > g_data.time_to_die)
			swap_status(PH_DEAD, (t_philo *)philo);
		pthread_mutex_unlock(&((t_philo *)philo)->eat_time_mutex);
		usleep(PH_MON_DEL);
	}
	return (0);
}