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

#include "philo_two.h"

void		*ph_monitor(void *philo)
{
	long	last_time;
	long	current_time;

	while (1)
	{
		if (g_data.if_some_philo_die || g_data.num_to_eat == ((t_philo *)
		philo)->num_of_eat)
			break ;
		sem_wait(((t_philo *)philo)->eat_time_sem);
		last_time = ((t_philo *)philo)->last_time_eat;
		current_time = ph_time();
		if ((current_time - last_time) > g_data.time_to_die)
			ph_swap_status(PH_DEAD, (t_philo *)philo);
		sem_post(((t_philo *)philo)->eat_time_sem);
		ph_usleep(PH_MON_DEL);
	}
	return (0);
}
