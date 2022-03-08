/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 14:46:59 by sikang           ###   ########.fr       */
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

void	init_stack(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	while(*argv)
	{
		if (check_number(*argv))
			ft_stackadd_back(&stack_a, ft_atoi(*argv));
		else
		{
			ft_stackclear(stack_a);
			ft_stackclear(stack_b);
			free(stack_a);
			free(stack_b);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	init_stack(stack_a, stack_b, argv);

	return (0);
}
