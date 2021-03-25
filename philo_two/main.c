/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:09:11 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 11:09:14 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_data		g_data;

int			main(int ac, char **av)
{
	int	status;

	status = 0;
	if (read_instructions(ac, av) == -1 || philo_init() == -1)
	{
		destroy_phil();
		status = 1;
	}
	ph_treads();
	ph_threads_join();
	destroy_phil();
	return (status);
}
