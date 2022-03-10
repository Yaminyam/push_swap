/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:10:21 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 15:35:09 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

static int	check_number(char *str)
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

static int	check_duplicate(t_stack *stack, int n)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->content == n)
			return (0);
		node = node->next;
	}
	return (1);
}

void	init_stack(t_stack *stack_a, char **argv, int *input)
{
	while(*argv)
	{
		ft_putstr_fd(*argv, 1);
		if (!check_number(*argv) || !check_duplicate(stack_a, ft_atoi(*argv)))
			error();
		ft_stackadd_back(stack_a, ft_atoi(*argv));
		*input = ft_atoi(*argv);
		input++;
		argv++;
	}
}
