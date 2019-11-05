/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:32:00 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 19:39:14 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_heap(t_minheap **minh, t_room *new)
{
	t_minheap	*mheap;
	t_room		*tmp;
	char		*str;
	int			i;

	mheap = *minh;
	mheap->elems++;
	str = to_binary(mheap->elems);
	tmp = mheap->root;
	i = 1;
	while (str[i + 1] != 0)
	{
		if (str[i] == '1')
			tmp = tmp->rheap;
		else
			tmp = tmp->lheap;
		i++;
	}
	if (str[i] == '1')
		tmp->rheap = new;
	else
		tmp->lheap = new;
	init_room(&new, tmp);
	free(str);
	heapify(minh, to_binary(mheap->elems));
}

int		update_heap(t_minheap **minh, t_room *changed)
{
	t_minheap	*mheap;
	t_room		*tmp;

	tmp = changed;
	mheap = *minh;
	while (tmp->pheap != NULL)
	{
		if (tmp->dist < tmp->pheap->dist)
		{
			heap_swap(mheap, tmp->pheap, tmp);
		}
		else
			break ;
	}
	return (1);
}

void	to_last(t_room *x, t_room *y)
{
	x->in_heap = 0;
	if (y == NULL)
		return ;
	if (y->pheap != NULL)
	{
		if (y->pheap->rheap == y)
		{
			y->pheap->rheap = NULL;
		}
		else if (y->pheap->lheap == y)
		{
			y->pheap->lheap = NULL;
		}
	}
	y->pheap = NULL;
	if (x->rheap != NULL)
		x->rheap->pheap = y;
	if (x->lheap != NULL)
		x->lheap->pheap = y;
	y->rheap = x->rheap;
	y->lheap = x->lheap;
}

void	reorder(t_minheap *mheap, t_room *tmp)
{
	int a;

	while (1)
	{
		if (tmp->rheap == NULL && tmp->lheap == NULL)
			break ;
		if (tmp->rheap == NULL)
			a = 1;
		else if (tmp->lheap == NULL)
			a = -1;
		else
			a = tmp->rheap->dist - tmp->lheap->dist;
		if ((tmp->rheap != NULL && tmp->dist > tmp->rheap->dist)
			|| (tmp->lheap != NULL && tmp->dist > tmp->lheap->dist))
		{
			if (a > 0)
				heap_swap(mheap, tmp, tmp->lheap);
			else
				heap_swap(mheap, tmp, tmp->rheap);
		}
		else
			break ;
	}
}

void	remove_min_elem(t_minheap **minh)
{
	t_minheap	*mheap;
	char		*str;
	t_room		*tmp;
	int			i;

	mheap = *minh;
	i = 0;
	str = to_binary(mheap->elems);
	mheap->elems--;
	if (mheap->elems <= 0)
	{
		free(str);
		return ;
	}
	tmp = mheap->root;
	tmp->in_heap = 0;
	while (str[++i] != 0)
		if (str[i] == '1')
			tmp = tmp->rheap;
		else
			tmp = tmp->lheap;
	free(str);
	to_last(mheap->root, tmp);
	mheap->root = tmp;
	reorder(mheap, tmp);
}
