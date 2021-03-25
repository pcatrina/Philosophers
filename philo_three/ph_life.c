/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:35:48 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 21:35:49 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			ph_usleep(int msec)
{
	long	current_time;

	current_time = ph_time();
	while (current_time + (long)msec > ph_time())
		usleep(PH_MON_DEL);
}

static	void	try_to_take_fork(t_philo *philo)
{
	sem_wait(g_data.steward);
	sem_wait(g_data.forks);
	ph_swap_status(PH_TAKE_FORK, philo);
	sem_wait(g_data.forks);
	ph_swap_status(PH_TAKE_FORK, philo);
	sem_post(g_data.steward);
}

void			*ph_life(void *philo)
{
	while (1)
	{
		try_to_take_fork((t_philo *)philo);
		sem_wait(((t_philo *)philo)->eat_time_sem);
		ph_swap_status(PH_EAT, (t_philo *)philo);
		sem_post(((t_philo *)philo)->eat_time_sem);
		ph_usleep(g_data.time_to_eat);
		sem_post(g_data.forks);
		sem_post(g_data.forks);
		if (g_data.num_to_eat == ((t_philo *)philo)->num_of_eat)
			break ;
		ph_swap_status(PH_SLEEPING, (t_philo *)philo);
		ph_usleep(g_data.time_to_sleep);
		ph_swap_status(PH_THINKING, (t_philo *)philo);
	}
	return (0);
}
