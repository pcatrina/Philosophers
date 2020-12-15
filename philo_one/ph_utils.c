/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:34:00 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 11:34:01 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - '0');
	return ((int)res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	i = nmemb * size;
	if (!(res = malloc(i)))
		return (0);
	ft_bzero(res, i);
	return (res);
}

void	ft_bzero(void *s, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = -1;
	while (++i < len)
		str[i] = 0;
}
