/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_open_main_sem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:17:29 by pcatrina          #+#    #+#             */
/*   Updated: 2021/01/08 11:17:31 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ph_open_main_sem(void)
{
	if ((g_data.forks = ph_open_sem("forks", g_data.num_philo)) == SEM_FAILED)
		return (-1);
	if ((g_data.steward = ph_open_sem("steward", 1)) == SEM_FAILED)
		return (-1);
	if ((g_data.out_sem = ph_open_sem("out_sem", 1)) == SEM_FAILED)
		return (-1);
	return (0);
}
