/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_open_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:29:04 by pcatrina          #+#    #+#             */
/*   Updated: 2021/01/08 10:29:06 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <errno.h>

int		*ph_open_sem(char *name, int i)
{
	sem_t	*sem;

	if ((sem = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, i)) == SEM_FAILED)
	{
		if (errno == EEXIST)
		{
			sem_unlink(name);
			sem = sem_open(name, O_CREAT | O_EXCL, S_IRWXU, i);
		}
	}
	return (sem);
}
