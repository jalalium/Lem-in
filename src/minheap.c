/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minheap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:18:00 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 19:40:46 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_minheap	*init_heap(t_room *start)
{
	t_minheap	*out;

	if (!(out = (t_minheap*)malloc(sizeof(t_minheap) * 1)))
		return (NULL);
	out->root = start;
	out->elems = 1;
	out->root->dist = 0;
	out->root->vis = 1;
	out->root->rheap = NULL;
	out->root->parent = NULL;
	out->root->lheap = NULL;
	out->root->pheap = NULL;
	return (out);
}

void		heapify(t_minheap **minh, char *str)
{
	t_minheap	*mheap;
	t_room		*tmp;
	int			i;

	mheap = *minh;
	tmp = mheap->root;
	i = 1;
	while (str[i] != 0)
	{
		if (str[i] == '1')
			tmp = tmp->rheap;
		else
			tmp = tmp->lheap;
		i++;
	}
	while (tmp->pheap != NULL)
	{
		if (tmp->dist < tmp->pheap->dist)
			heap_swap(mheap, tmp->pheap, tmp);
		else
			break ;
	}
	free(str);
}

int			bin_len(int x)
{
	int count;

	count = 1;
	while (x > 0)
	{
		x /= 2;
		count++;
	}
	return (count);
}

char		*to_binary(int x)
{
	int		tmp;
	int		count;
	char	*out;
	int		i;

	tmp = x;
	count = bin_len(tmp);
	if (x == 0)
		count = 2;
	out = (char*)malloc(sizeof(char) * (count));
	out[count - 1] = 0;
	tmp = x;
	i = count - 2;
	while (tmp > 0)
	{
		out[i] = tmp % 2 + 48;
		tmp /= 2;
		i--;
	}
	if (x == 0)
		out[0] = '0';
	return (out);
}

void		init_room(t_room **tmp, t_room *x)
{
	t_room *a;

	a = *tmp;
	a->pheap = x;
	a->lheap = NULL;
	a->rheap = NULL;
	a->in_heap = 1;
}
