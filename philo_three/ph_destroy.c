/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:45:10 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 19:45:12 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <errno.h>

int	destroy_phil(int status)
{
	int i;

	i = 0;
	while (g_data.philo && (++i < g_data.num_philo))
	{
		sem_close(g_data.philo[i].eat_time_sem);
		if (errno == EINVAL)
			status = errno;
	}
	sem_close(g_data.out_sem);
	if (errno == EINVAL)
		status = errno;
	sem_close(g_data.steward);
	if (errno == EINVAL)
		status = errno;
	sem_close(g_data.forks);
	if (errno == EINVAL)
		status = errno;
	free(g_data.philo);
	free(g_data.philo_pids);
	return (status);
}
