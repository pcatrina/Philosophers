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

#include "philo_one.h"

static	void try_to_take_fork(t_philo *philo)
{
	if (philo->i % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	swap_status(PH_TAKE_FORK, philo);
	if (!(philo->i % 2))
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	swap_status(PH_TAKE_FORK, philo);
}

static	void put_back_fork(t_philo *philo)
{
	if (philo->i % 2)
		pthread_mutex_unlock(philo->left_fork);
	else
		pthread_mutex_unlock(philo->right_fork);
	if (!(philo->i % 2))
		pthread_mutex_unlock(philo->left_fork);
	else
		pthread_mutex_unlock(philo->right_fork);
}

void	*ph_life(void *philo)
{
	while (1)
	{
		if (g_data.if_some_philo_die)
			break ;
		try_to_take_fork((t_philo *)philo);
		pthread_mutex_lock(&((t_philo *)philo)->eat_time_mutex);
		swap_status(PH_EAT,(t_philo *)philo);
		pthread_mutex_unlock(&((t_philo *)philo)->eat_time_mutex);
		usleep(g_data.time_to_eat);
		put_back_fork((t_philo *)philo);
		swap_status(PH_SLEEPING, (t_philo *)philo);
		usleep(g_data.time_to_sleep);
		swap_status(PH_THINKING, (t_philo *)philo);
	}
	return (0);
}