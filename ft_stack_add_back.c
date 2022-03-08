/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:36:20 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 14:13:45 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack **lst, t_node *new)
{
	t_node *last;

	if ((*lst)->bottom == 0) {
		*lst = new;
		return;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
