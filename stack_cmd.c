/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:14:49 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 16:15:28 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *lst)
{
	int		tmp;
	t_node	*node;

	if (lst->size < 2)
		return ;
	node = lst->top;
	tmp = node->content;
	node->content = node->next->content;
	node->next->content = tmp;
}

void	ft_rotate(t_stack *lst)
{
	t_node	*node;
	t_node	*tmp;

	if (lst->size < 2)
		return ;
	node = lst->top;
	tmp = node->next;
	node->prev = lst->bottom;
	node->next = NULL;
	lst->bottom->next = node;
	lst->bottom = node;
	tmp->prev = NULL;
	lst->top = tmp;
}

void	ft_push(t_stack *lst, t_stack *lst2)
{
	t_node	*node;
	t_node	*tmp;

	if (lst->size < 1)
		return ;
	node = lst->top;
	tmp = node->next;
	node->next = lst2->top;
	lst2->top = node;
	tmp->prev = NULL;
	lst->top = tmp;
	lst->size--;
}

void	ft_rev_rotate(t_stack *lst)
{
	t_node	*node;
	t_node	*tmp;

	if (lst->size < 2)
		return ;
	node = lst->bottom;
	tmp = node->prev;
	node->prev = NULL;
	node->next = lst->top;
	node->next->prev = node;
	lst->top = node;
	tmp->next = NULL;
	lst->bottom = tmp;
}
