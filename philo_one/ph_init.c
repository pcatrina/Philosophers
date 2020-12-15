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

int		philo_init(void)
{
//	int		i;
//	int		real_time;

	if (!(g_data.philo = ft_calloc(g_data.num_philo, sizeof(t_philo))))
		return (ph_error(PH_FATAL_ER));
	return (0);
}