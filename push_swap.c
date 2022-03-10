/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 15:43:57 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *stack_a, t_stack *stack_b, int size)
{
	int max_num;
	int max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0) ++max_bits;
	for (int i = 0; i < max_bits; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			int num = stack_a->top->content;
			if (((num >> i) & 1) == 1) {
				ft_putstr_fd("ra\n", 1);
				ft_rotate(stack_a);
			}
			else {
				ft_putstr_fd("pb\n", 1);
				ft_push(stack_a, stack_b);
			}
		}
		while (stack_b->size) {
			ft_putstr_fd("pa\n", 1);
			ft_push(stack_b, stack_a);
		}
	}
}

int		main(int argc, char **argv)
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
	rescale(stack_a, input, argc - 1);
	push_swap(stack_a, stack_b, argc - 1);
	return (0);
}
