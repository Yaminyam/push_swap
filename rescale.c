/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:15:53 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 14:01:34 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rescale(t_stack *stack, int *input, int n)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		while (i < n)
		{
			if (node->content == input[i])
			{
				node->content = i;
				break ;
			}
			i++;
		}
	}
}
