/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:42:26 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/16 19:42:27 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int 		ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_res(char *res, int count, int i, int n)
{
	if (n == 0)
	{
		res[count++] = '0';
		res[count] = '\0';
		return (res);
	}
	while (n / i > 9)
		i *= 10;
	while (i /= 10 != 1)
	{
		res[count++] = n / i + '0';
		n %= i;
		i /= 10;
	}
	res[count] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		count;
	int		i;

	i = 1;
	count = 0;
	if (n < 0)
	{
		if (!(res = (char*)malloc(sizeof(char) * ft_len(n) + 2)))
			return (0);
		res[count++] = '-';
		if (n == -2147483648)
		{
			res[count++] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	else
	{
		if (!(res = (char*)malloc(sizeof(char) * ft_len(n) + 1)))
			return (0);
	}
	return (ft_res(res, count, i, n));
}
