/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_status_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:09:52 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/16 19:09:54 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	make_message(char *buf, int time, int status, t_philo *philo)
{
	char *tmp;

	tmp = ft_itoa(time);
	memset(buf, '\0', PH_BUFF);
	ft_putsrt_to_buf(tmp, buf);
	ft_free_str(tmp);
	ft_putsrt_to_buf(" ", buf);
	tmp = ft_itoa(philo->i);
	ft_putsrt_to_buf(tmp, buf);
	ft_free_str(tmp);
	ft_putsrt_to_buf(" ", buf);
	tmp = ft_itoa(status);
	ft_putsrt_to_buf(tmp,buf);
	ft_free_str(tmp);
}

void	ph_write_status(int time, int status, t_philo *philo)
{
	static char buf[PH_BUFF];

	make_message(buf, time, status, philo);
	write (1, buf, ft_strlen(buf));
}
