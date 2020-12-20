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

void			ph_usleep(int msec)
{
	long	current_time;

	current_time = ph_time();
	while (current_time + (long)msec > ph_time())
		usleep(PH_MON_DEL);
}

static	void	try_to_take_fork(t_philo *philo)
{
	if (philo->i % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ph_swap_status(PH_TAKE_FORK, philo);
	if (!(philo->i % 2))
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ph_swap_status(PH_TAKE_FORK, philo);
}

static	void	put_back_fork(t_philo *philo)
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

void			*ph_life(void *philo)
{
	while (1)
	{
		if (g_data.if_some_philo_die || g_data.num_to_eat == ((t_philo *)
				philo)->num_of_eat)
			break ;
		try_to_take_fork((t_philo *)philo);
		pthread_mutex_lock(&((t_philo *)philo)->eat_time_mutex);
		ph_swap_status(PH_EAT, (t_philo *)philo);
		pthread_mutex_unlock(&((t_philo *)philo)->eat_time_mutex);
		ph_usleep(g_data.time_to_eat);
		put_back_fork((t_philo *)philo);
		if (g_data.num_to_eat == ((t_philo *)philo)->num_of_eat)
			break ;
		ph_swap_status(PH_SLEEPING, (t_philo *)philo);
		ph_usleep(g_data.time_to_sleep);
		ph_swap_status(PH_THINKING, (t_philo *)philo);
	}
	return (0);
}
