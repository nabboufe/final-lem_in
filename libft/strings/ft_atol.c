/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: affect <affect@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:18:16 by affect            #+#    #+#             */
/*   Updated: 2020/03/14 13:21:23 by affect           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *str)
{
	long long result;
	long long sign;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = (sign * -1);
		str++;
	}
	while (*str > 47 && *str < 58)
		result = (*str++ - 48) + (result * 10);
	return ((long)(sign * result));
}