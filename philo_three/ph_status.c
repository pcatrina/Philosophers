/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:06:45 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/16 19:06:47 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		ph_if_status_eat(int status, t_philo *philo, long time)
{
	philo->last_time_eat = ph_time();
	if (g_data.num_to_eat != -1)
	{
		philo->num_of_eat++;
		ph_write_status((int)time, status, philo);
		if (g_data.num_to_eat == philo->num_of_eat)
		{
			sem_post(g_data.phil_eat_sem);
			sem_wait(g_data.out_sem);
		}
	}
	else
		ph_write_status((int)time, status, philo);
}

void			ph_swap_status(int status, t_philo *philo)
{
	long	time;

	sem_wait(g_data.out_sem);
	time = ph_time() - g_data.start_time;
	if (status == 3)
		ph_if_status_eat(status, philo, time);
	else if (status == 6)
	{
		ph_write_status((int)time, status, philo);
		free(g_data.philo);
		free(g_data.philo_pids);
		exit(0);
	}
	else
		ph_write_status((int)time, status, philo);
	sem_post(g_data.out_sem);
}
