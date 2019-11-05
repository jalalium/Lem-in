/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_yen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:34:17 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/16 20:18:29 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	mark_forbidden_nodes(t_room **nodes)
{
	int	i;

	i = 0;
	if (nodes != NULL)
	{
		while (nodes[i] != NULL)
		{
			nodes[i]->vis = 2;
			i++;
		}
	}
}

void	visit_new_y(t_room *tmp, t_room *parent, t_minheap **y)
{
	tmp->vis = 1;
	tmp->dist = parent->dist + 1;
	tmp->parent = parent;
	add_to_heap(y, tmp);
}

void	visit_old_y(t_room *tmp, t_room *parent, t_minheap **y)
{
	tmp->dist = parent->dist + 1;
	tmp->parent = parent;
	update_heap(y, tmp);
}

void	free_it(t_room ***nodes, t_room ***used, t_minheap **x)
{
	free(*nodes);
	free(*used);
	free(*x);
}

t_path	*dijkstra_three(t_info info, t_room **used, t_room **nodes, t_room *sr)
{
	t_minheap	*x;
	t_room		**tmp;
	int			i;
	int			z;

	unmark_avl(info.root);
	x = init_heap(info.end);
	mark_forbidden_nodes(nodes);
	while (x->elems != 0)
	{
		tmp = x->root->child;
		i = -1;
		while (tmp[++i] != NULL)
		{
			z = not_used(used, x->root, tmp[i]);
			if (tmp[i]->vis == 0 && z)
				visit_new_y(tmp[i], x->root, &x);
			else if (tmp[i]->vis == 1 && tmp[i]->dist > x->root->dist +
			tmp[i]->children * tmp[i]->children && z && tmp[i]->in_heap == 1)
				visit_old_y(tmp[i], x->root, &x);
		}
		remove_min_elem(&x);
	}
	free_it(&nodes, &used, &x);
	return (output_path(sr, info.end));
}
