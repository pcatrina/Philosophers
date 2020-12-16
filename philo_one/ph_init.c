/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:06:55 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 12:06:56 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo_one.h"

static void 		init_start_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int 				ph_time(void)
{
	struct timeval	tv;
	long 			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return ((int)current_time);
}

int					mutex_init(int i)
{
	if (!((g_data.philo)[i].left_fork = ft_calloc(1, sizeof(pthread_mutex_t))))
		return (ph_error(PH_FATAL_ER));
	if (pthread_mutex_init((g_data.philo)[i].left_fork, NULL))
	{
		free((g_data.philo)[i].left_fork);
		(g_data.philo)[i].left_fork = NULL;
		return (-1);
	}
	if (pthread_mutex_init(&(g_data.philo)[i].eat_time_mutex, NULL))
	{
		pthread_mutex_destroy((g_data.philo)[i].left_fork);
		free((g_data.philo)[i].left_fork);
		(g_data.philo)[i].left_fork = NULL;
		return (-1);
	}
	return (0);
}

int					philo_init(void)
{
	int		i;
	int		real_time;

	i = -1;
	if (!(g_data.philo = ft_calloc(g_data.num_philo, sizeof(t_philo))))
		return (ph_error(PH_FATAL_ER));
	init_start_time();
	real_time = ph_time();
	while (++i < g_data.num_philo)
	{
		(g_data.philo)[i].last_time_eat = real_time;
		(g_data.philo)[i].i = i + 1;
		if (mutex_init(i) == -1)
			return (ph_error(PH_FATAL_ER));
		if (i > 0)
			(g_data.philo)[i].left_fork = (g_data.philo)[i - 1].right_fork;
	}
	(g_data.philo)[0].right_fork = (g_data.philo)[g_data.num_philo - 1]
			.left_fork;
	return (0);
}