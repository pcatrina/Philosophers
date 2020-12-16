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

#include "philo_one.h"

void	swap_status(int status, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&g_data.out_mutex);
	if (!g_data.if_some_philo_die)
	{
		time = ph_time();
		ph_write_status(time, status, philo);
	}
	pthread_mutex_unlock(&g_data.out_mutex);
}