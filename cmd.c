/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:09:21 by sikang            #+#    #+#             */
/*   Updated: 2022/03/14 17:46:11 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	ft_putstr_fd(cmd, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strncmp(cmd, "sa", 2) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		ft_rev_rotate(stack_a);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		ft_rev_rotate(stack_b);
}

void	cmd_d(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	ft_putstr_fd(cmd, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strncmp(cmd, "ss", 2) == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (ft_strncmp(cmd, "rr", 2) == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
}
