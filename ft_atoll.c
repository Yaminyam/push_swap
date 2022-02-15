/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:53:11 by sikang            #+#    #+#             */
/*   Updated: 2022/02/14 15:57:15 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	unsigned long long	sum;
	int					pm;

	sum = 0;
	pm = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pm *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		sum *= 10;
		sum += *str - '0';
		str++;
	}
	if (sum > LLONG_MAX - 1 && pm == -1)
		return (0);
	if (sum > LLONG_MAX && pm == 1)
		return (-1);
	return (pm * sum);
}
