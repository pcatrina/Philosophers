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

#include "philo_three.h"

t_data		g_data;

int			main(int ac, char **av)
{
	int status;

	status = 0;
	if (read_instructions(ac, av) == -1 || philo_init() == -1 ||
	ph_run_process() == -1)
		status = 1;
	destroy_phil(status);
	return (status);
}
