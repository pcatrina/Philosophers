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

#include "philo_one.h"

t_data		g_data;

int			main(int ac, char **av)
{
	if (read_instructions(ac, av) == -1 || philo_init() == -1 ||
	pthread_mutex_init(&g_data.out_mutex, NULL))
	{
		destroy_phil();
		return (1);
	}
	return (0);
}