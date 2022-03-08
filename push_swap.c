/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 13:53:34 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_number(char *str)
{
	unsigned long long	sum;
	int					pm;

	sum = 0;
	pm = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '-')
		pm *= -1;
	if (ft_strlen(str) > 10)
		return (0);
	while (*str) {
		if (!('0' <= *str && *str <= '9'))
			return (0);
		sum *= 10;
		sum += *str - '0';
		str++;
	}
	if (sum > INT_MAX - 1 && pm == -1)
		return (0);
	if (sum > INT_MAX && pm == 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*numbers;

	numbers = (int *)malloc(sizeof(int) * argc);
	while(*argv)
	{
		if (check_number(*argv))
			*numbers = ft_atoi(*argv);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		numbers++;
		*argv++;
	}
	return (0);
}
