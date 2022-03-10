/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:45:17 by sikang            #+#    #+#             */
/*   Updated: 2022/03/10 10:52:35 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void	quick_sort(int arr[], int left, int right)
{
	int	L;
	int	R;
	int	pivot;

	L = left;
	R = right;
	pivot = arr[(left + right) / 2];
	while (L <= R)
	{
		while (arr[L] < pivot)
			L++;
		while (arr[R] > pivot)
			R--;
		if (L <= R)
		{
			swap(&arr[L], &arr[R]);
			L++;
			R--;
		}
	}
	if (left < R)
		quick_sort(arr, left, R);
	if (L < right)
		quick_sort(arr, L, right);
}
