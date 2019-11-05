/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:30:26 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 19:40:12 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	heap_swap_left(t_room *x, t_room *y)
{
	t_room		*tmp;
	t_room		*tmp3;

	tmp = x->rheap;
	tmp3 = x->pheap;
	x->rheap = y->rheap;
	if (y->rheap != NULL)
		y->rheap->pheap = x;
	x->lheap = y->lheap;
	if (y->lheap != NULL)
		y->lheap->pheap = x;
	x->pheap = y;
	y->rheap = tmp;
	if (tmp != NULL)
		tmp->pheap = y;
	y->lheap = x;
	y->pheap = tmp3;
	if (tmp3 != NULL)
	{
		if (tmp3->rheap == x)
			tmp3->rheap = y;
		if (tmp3->lheap == x)
			tmp3->lheap = y;
	}
}

void	heap_swap_right(t_room *x, t_room *y)
{
	t_room		*tmp;
	t_room		*tmp3;

	tmp = x->lheap;
	tmp3 = x->pheap;
	x->rheap = y->rheap;
	if (y->rheap != NULL)
		y->rheap->pheap = x;
	x->lheap = y->lheap;
	if (y->lheap != NULL)
		y->lheap->pheap = x;
	x->pheap = y;
	y->lheap = tmp;
	if (tmp != NULL)
		tmp->pheap = y;
	y->rheap = x;
	y->pheap = tmp3;
	if (tmp3 != NULL)
	{
		if (tmp3->rheap == x)
			tmp3->rheap = y;
		if (tmp3->lheap == x)
			tmp3->lheap = y;
	}
}

void	heap_swap(t_minheap *a, t_room *x, t_room *y)
{
	if (a->root == x)
		a->root = y;
	if (x->lheap == y)
		heap_swap_left(x, y);
	else if (x->rheap == y)
		heap_swap_right(x, y);
}
