/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:25 by sikang            #+#    #+#             */
/*   Updated: 2022/03/14 16:50:27 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next)
	{
		if (node->content > node->next->content)
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

static void	push_swap(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			num = stack_a->top->content;
			if ((num >> i) & 1)
				cmd(stack_a, stack_b, "ra");
			else
				cmd(stack_a, stack_b, "pb");
		}
		while (stack_b->size)
			cmd(stack_a, stack_b, "pa");
		i++;
	}
}

static void	small3_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	arr[3];

	arr[0] = stack_a->top->content;
	arr[1] = stack_a->top->next->content;
	arr[2] = stack_a->top->next->next->content;
	if (arr[1] < arr[0] && arr[0] < arr[2])
		cmd(stack_a, stack_b, "sa");
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		cmd(stack_a, stack_b, "ra");
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		cmd(stack_a, stack_b, "rra");
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		cmd(stack_a, stack_b, "sa");
		cmd(stack_a, stack_b, "rra");
	}
	else if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		cmd(stack_a, stack_b, "pb");
		cmd(stack_a, stack_b, "sa");
	}
}

static void	small5_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	j;
	int	num;

	j = 0;
	while (j++ < 5)
	{
		num = stack_a->top->content;
		if (num < 2)
			cmd(stack_a, stack_b, "pb");
		else
			cmd(stack_a, stack_b, "ra");
	}
	small3_push_swap(stack_a, stack_b);
	while (stack_b->size)
		cmd(stack_a, stack_b, "pa");
	if (!is_sorted(stack_a))
		cmd(stack_a, stack_b, "sa");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*input;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	input = (int *)malloc(sizeof(int) * (argc - 1));
	init_stack(stack_a, stack_b, argv + 1, input);
	quick_sort(input, 0, argc - 2);
	rescale(stack_a, input, argc - 1);
	if (argc - 1 == 3)
		small3_push_swap(stack_a, stack_b);
	else if (argc - 1 == 5)
		small5_push_swap(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b, argc - 1);
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	free(stack_a);
	free(stack_b);
	free(input);
	return (0);
}
