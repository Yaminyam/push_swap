/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:36:20 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 14:29:36 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack *lst, int	n)
{
	t_node	*last;
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->content = n;
	if (lst->size == 0) {
		lst->bottom = new;
		lst->top = new;
		lst->size++;
		return;
	}
	last = lst->bottom;
	last->next = new;
	new->prev = last;
	lst->bottom = new;
	lst->size++;
}
