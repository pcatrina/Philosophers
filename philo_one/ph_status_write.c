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

static	void	print_status(int status, char *buf)
{
	if (status == PH_TAKE_FORK)
		ft_putsrt_to_buf(PH_LINE_TAKE, buf);
	if (status == PH_EAT)
		ft_putsrt_to_buf(PH_LINE_EAT, buf);
	if (status == PH_SLEEPING)
		ft_putsrt_to_buf(PH_LINE_SLEEP, buf);
	if (status == PH_THINKING)
		ft_putsrt_to_buf(PH_LINE_THINKING, buf);
	if (status == PH_DEAD)
		ft_putsrt_to_buf(PH_LINE_DEAD, buf);
}

static	void	make_message(char *buf, int time, int status, t_philo *philo)
{
	memset(buf, '\0', PH_BUFF);
	ft_putnbr_to_buf(time, buf);
	ft_putsrt_to_buf(" ", buf);
	ft_putnbr_to_buf(philo->i, buf);
	ft_putsrt_to_buf(" ", buf);
	print_status(status, buf);
	if (philo->num_of_eat == g_data.num_to_eat && status == PH_THINKING)
	{
		ft_putsrt_to_buf(" | count of Eat = ", buf);
		ft_putnbr_to_buf(philo->num_of_eat, buf);
	}
	ft_putsrt_to_buf("\n", buf);
}

void			ph_write_status(int time, int status, t_philo *philo)
{
	static char buf[PH_BUFF];

	make_message(buf, time, status, philo);
	write(1, buf, ft_strlen(buf));
}
