/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_treads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:17:09 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 20:17:10 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		ph_treads(void)
{
	int	i;

	i = -1;
	while (++i < g_data.num_philo)
	{
		pthread_create(&g_data.philo[i].philo_tread, NULL, ph_life, \
				g_data.philo + i);
		pthread_create(&g_data.philo[i].monitoring_thread, NULL, \
				ph_monitor, g_data.philo + i);
	}
}

void		ph_threads_join(void)
{
	int	i;

	i = -1;
	while (++i < g_data.num_philo)
	{
		pthread_join(g_data.philo[i].philo_tread, NULL);
		pthread_join(g_data.philo[i].monitoring_thread, NULL);
	}
}
