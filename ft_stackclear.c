/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:53:47 by sikang            #+#    #+#             */
/*   Updated: 2022/03/11 19:58:03 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackclear(t_stack *lst)
{
	t_node	*node;

	node = lst->top;
	while (node)
	{
		lst->top = node->next;
		free(node);
		node = lst->top;
	}
	lst->bottom = 0;
	lst->size = 0;
}
