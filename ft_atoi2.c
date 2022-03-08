/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:53:11 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 10:46:56 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	ft_atoi2(const char *str)
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
	if (sum > INT_MAX - 1 && pm == -1)
		return (-1);
	if (sum > INT_MAX && pm == 1)
		return (-1);
	return (pm * sum);
}
