/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:31:50 by sikang            #+#    #+#             */
/*   Updated: 2022/03/08 14:28:58 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "./libft/libft.h"

typedef struct	s_node {
	int		*content;
	struct	s_node *next;
	struct	s_nodd *prev;
}				t_node;

typedef struct	s_stack {
	int		size;
	t_node	*top;
	t_node	*bottom;
}				t_stack;

void	ft_stackadd_back(t_stack *lst, int n);

#endif
