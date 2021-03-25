/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_putstr_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:12:08 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/20 20:12:10 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static long		mult_10(int n)
{
	long		num;

	num = 1;
	while (n--)
		num *= 10;
	return (num);
}

static int		count(int n)
{
	int		i;

	i = 1;
	while (n / mult_10(i) != 0)
		i++;
	return (i);
}

void			ft_putnbr_to_buf(int n, char *buf)
{
	int		num;
	int		i;

	num = count(n);
	i = ft_strlen(buf);
	if (n >= 0)
		n *= (-1);
	else
		buf[i++] = '-';
	while (num--)
	{
		buf[i] = (-1) * ((n / mult_10(num)) % 10 - 48);
		i++;
	}
}
