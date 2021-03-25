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
#include "philo_three.h"

long				ph_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int					init_eat_time_sem(int i)
{
	char	buf[PH_SEM_BUFF];

	memset(buf, '\0', PH_SEM_BUFF);
	ft_putsrt_to_buf("eat_time_sem", buf);
	ft_putnbr_to_buf(i, buf);
	if ((g_data.philo[i].eat_time_sem = ph_open_sem(buf, 1)) == SEM_FAILED)
		return (-1);
	return (0);
}

int					philo_init(void)
{
	int			i;

	i = -1;
	if (!(g_data.philo = ft_calloc(g_data.num_philo, sizeof(t_philo))) || !
	(g_data.philo_pids = ft_calloc(g_data.num_philo, sizeof(int))))
		return (ph_error(PH_FATAL_ER));
	if (ph_open_main_sem() == -1)
		return (ph_error(PH_SEM_ERROR));
	g_data.start_time = ph_time();
	while (++i < g_data.num_philo)
	{
		(g_data.philo)[i].last_time_eat = ph_time();
		(g_data.philo)[i].i = i + 1;
		if (init_eat_time_sem(i) == -1)
			return (ph_error(PH_SEM_ERROR));
	}
	return (0);
}
