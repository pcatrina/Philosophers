/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:29:36 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 11:29:37 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}

static int	is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int			read_instructions(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
		if (!is_number(av[i]))
			return (ph_error(PH_ER_ARG_NOT_DIG));
	if (ac < 5 || ac > 6)
		return (ph_error(PH_ER_NUM_ARG));
	if ((g_data.num_philo = ft_atoi(av[1])) < 2)
		return (ph_error(PH_ER_FEW_PHIL));
	g_data.time_to_die = ft_atoi(av[2]);
	g_data.time_to_eat = ft_atoi(av[3]);
	g_data.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		g_data.num_to_eat = ft_atoi(av[5]);
	else
		g_data.num_to_eat = -1;
	if (g_data.num_to_eat == 0)
		ph_error(PH_ER_EAT_NUM);
	return (0);
}
