/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_run_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:53:56 by pcatrina          #+#    #+#             */
/*   Updated: 2021/01/09 15:53:58 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

static	void		*ph_check_eat(void *pid)
{
	int		i;

	i = 0;
	if (g_data.num_to_eat != -1)
	{
		while (i < g_data.num_philo)
		{
			if (i > 0)
				sem_post(g_data.out_sem);
			sem_wait(g_data.phil_eat_sem);
			i++;
		}
		kill(*(int *)pid, SIGKILL);
	}
	return (0);
}

static	void		ph_kill_process(pid_t pid)
{
	int		i;

	i = 0;
	while (i < g_data.num_philo)
	{
		if (g_data.philo_pids[i] && g_data.philo_pids[i] != pid)
			kill(g_data.philo_pids[i], SIGKILL);
		i++;
	}
}

static	int			ph_process_error(pid_t pid)
{
	ph_kill_process(pid);
	ph_error(PH_ER_PROCESS);
	return (-1);
}

static	void		ph_child_process(int i)
{
	pthread_create(&g_data.philo[i].philo_tread, NULL, ph_life, \
				g_data.philo + i);
	pthread_create(&g_data.philo[i].monitoring_thread, NULL, \
				ph_monitor, g_data.philo + i);
	pthread_join(g_data.philo[i].philo_tread, NULL);
	pthread_join(g_data.philo[i].monitoring_thread, NULL);
}

int					ph_run_process(void)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < g_data.num_philo)
	{
		pid = fork();
		g_data.philo_pids[i] = pid;
		if (pid < 0)
			return (ph_process_error(pid));
		else if (pid == 0)
		{
			ph_child_process(i);
			ph_error(PH_ER_PROCESS);
		}
		else
			i++;
	}
	pthread_create(&g_data.chek_num_eat, NULL, ph_check_eat, &pid);
	pthread_detach(g_data.chek_num_eat);
	pid = waitpid(-1, NULL, 0);
	ph_kill_process(pid);
	return (0);
}
