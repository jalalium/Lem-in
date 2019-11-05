/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:20:14 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/16 20:12:53 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	visit_new_i(t_room *tmp, t_room *parent, t_minheap **y)
{
	tmp->vis = 1;
	tmp->dist = parent->dist + tmp->children;
	tmp->parent = parent;
	add_to_heap(y, tmp);
}

void	visit_old_i(t_room *tmp, t_room *parent, t_minheap **y)
{
	tmp->dist = parent->dist + tmp->children;
	tmp->parent = parent;
	update_heap(y, tmp);
}

int		children_visited(t_room *x)
{
	int t;
	int i;

	t = 0;
	i = 0;
	while (x->child[i] != NULL)
	{
		if (x->child[i]->vis != 0)
			t++;
		i++;
	}
	return (t);
}

t_path	*dijkstra_inter(t_info info)
{
	t_minheap	*x;
	t_room		**tmp;
	int			i;

	unmark_avl(info.root);
	x = init_heap(info.end);
	while (x->elems > 0)
	{
		tmp = x->root->child;
		i = -1;
		if (x->root->used != 1)
		{
			while (tmp[++i] != NULL)
			{
				if (tmp[i]->vis == 0)
					visit_new_i(tmp[i], x->root, &x);
				else if (tmp[i]->vis == 1 && tmp[i]->dist > x->root->dist
						+ tmp[i]->children && tmp[i]->in_heap == 1)
					visit_old_i(tmp[i], x->root, &x);
			}
		}
		remove_min_elem(&x);
	}
	free(x);
	return (output_path(info.start, info.end));
}
