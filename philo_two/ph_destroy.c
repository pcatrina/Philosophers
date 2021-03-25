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

#include "philo_two.h"

void	destroy_phil(void)
{
	int i;

	i = -1;
	while (g_data.philo && (g_data.philo)[++i].eat_time_sem && \
							(++i < g_data.num_philo))
		sem_close(g_data.philo[i].eat_time_sem);
	sem_close(g_data.out_sem);
	sem_close(g_data.steward);
	sem_close(g_data.forks);
	free(g_data.philo);
}
