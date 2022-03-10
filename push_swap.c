/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 17:44:43 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = stack_a->top->content;
			if (((num >> i) & 1) == 1)
				cmd(stack_a, stack_b, "ra");
			else
				cmd(stack_a, stack_b, "pb");
			j++;
		}
		while (stack_b->size)
			cmd(stack_a, stack_b, "pa");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
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
	init_stack(stack_a, argv + 1, input);
	quick_sort(input, 0, argc - 2);
	rescale(stack_a, input, argc - 1);
	push_swap(stack_a, stack_b, argc - 1);
	return (0);
}
