/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:31:29 by pcatrina          #+#    #+#             */
/*   Updated: 2020/12/15 11:31:31 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ph_error(char *str)
{
	write(2, PH_ERROR_INIT, ft_strlen(PH_ERROR_INIT));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (-1);
}
