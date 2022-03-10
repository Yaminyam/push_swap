/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 11:21:01 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rescale(stack_a, input, argc - 1);
	return (0);
}
