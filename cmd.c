/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:09:21 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 17:23:37 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	ft_putstr_fd(cmd, 1);
	if (ft_strcmp(cmd, "sa") == 0)
		ft_swap(stack_a);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_swap(stack_b);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(cmd, "pa") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(cmd, "ra") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(cmd, "rra") == 0)
		ft_rev_rotate(stack_a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_rev_rotate(stack_b);
}

void	cmd_d(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	ft_putstr_fd(cmd, 1);
	if (ft_strcmp(cmd, "ss") == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (ft_strcmp(cmd, "rr") == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (ft_strcmp(cmd, "rrr") == 0)
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
}
