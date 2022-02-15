/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/02/14 16:50:53 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *n)
{
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
	return (1);
}

int	main(int argc, char **argv)
{
	char **number;
	number = ft_split(argv, ' ');
	while(number)
	{
		if (check_number(number))
			ft_atoi(*number);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		number++;
	}
	return (0);
}
