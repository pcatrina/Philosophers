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

#include "philo_two.h"

static	void	if_philo_ate(int i)
{
	if (i < g_data.num_to_eat)
		return ;
	if (i > g_data.num_to_eat)
		g_data.if_some_philo_die = 1;
}

void			ph_swap_status(int status, t_philo *philo)
{
	long	time;

	sem_wait(g_data.out_sem);
	if (!g_data.if_some_philo_die)
	{
		time = ph_time() - g_data.start_time;
		if (status == PH_EAT)
		{
			philo->last_time_eat = ph_time();
			if (g_data.num_to_eat != -1)
			{
				philo->num_of_eat++;
				if_philo_ate(philo->num_of_eat);
			}
		}
		else if (status == PH_DEAD)
			g_data.if_some_philo_die = 1;
		ph_write_status((int)time, status, philo);
	}
	sem_post(g_data.out_sem);
}
