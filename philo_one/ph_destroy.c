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

#include "philo_one.h"

void	destroy_phil(void)
{
	int i;

	i = -1;
	while (g_data.philo && (g_data.philo)[++i].left_fork && \
							(++i < g_data.num_philo))
	{
		pthread_mutex_destroy((g_data.philo)[i].left_fork);
		free((g_data.philo)[i].left_fork);
		(g_data.philo)[i].left_fork = NULL;
		pthread_mutex_destroy(&(g_data.philo)[i].eat_time_mutex);
	}
	free(g_data.philo);
}
