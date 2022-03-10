/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 17:42:00 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int		check_number(char *str)
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

int		check_duplicate(t_stack *stack, int n)
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

void	init_stack(t_stack *stack_a, t_stack *stack_b, char **argv, int *input)
{
	while(*argv)
	{
		if (!check_number(*argv) || !check_duplicate(stack_a, ft_atoi(*argv)))
			error();
		ft_stackadd_back(stack_a, ft_atoi(*argv));
		*input = ft_atoi(*argv);
		input++;
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;
	int		*input;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	input = (int *)malloc(sizeof(int) * (argc - 1));
	stack_a->size = 0;
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	init_stack(stack_a, stack_b, argv, input);
	return (0);
}
