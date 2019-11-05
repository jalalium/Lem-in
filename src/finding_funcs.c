/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:50:16 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 19:36:23 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_paths		*init_paths(t_path *sp)
{
	t_paths	*all_paths;

	all_paths = (t_paths*)malloc(sizeof(t_paths) * 1);
	all_paths->count = 0;
	all_paths->first = sp;
	all_paths->last = sp;
	return (all_paths);
}

t_paths		*find_and_erase(t_info info, t_path *sp, int x)
{
	int		i;
	int		j;
	t_path	*tmp;
	t_paths	*all_paths;

	all_paths = init_paths(sp);
	add_path(&all_paths, sp, info);
	i = 0;
	j = 0;
	while (all_paths->count < 200)
	{
		if (x == 0)
			tmp = dijkstra_inter(info);
		else
			tmp = (all_paths->count % 2 != x ? dijkstra_len(info) :
					dijkstra_inter(info));
		if (tmp != NULL)
			add_path(&all_paths, tmp, info);
		else
			break ;
	}
	return (all_paths);
}

void		calculate_inodes(t_path *new, t_info info)
{
	int i;

	i = 0;
	new->inodes = 0;
	while (i < new->length)
	{
		if (new->path[i]->children > 2 && new->path[i] != info.start
				&& new->path[i] != info.end)
			new->inodes++;
		i++;
	}
}

void		id_path(t_path *new, t_info info)
{
	t_room	**id;
	int		i;
	int		j;

	calculate_inodes(new, info);
	id = (t_room**)malloc(sizeof(t_room*) * (new->inodes + 1));
	i = 0;
	j = 0;
	while (i < new->length)
	{
		if (new->path[i]->children > 2 && new->path[i] != info.start
			&& new->path[i] != info.end)
		{
			new->path[i]->mark = 0;
			id[j] = new->path[i];
			j++;
		}
		i++;
	}
	id[j] = NULL;
	new->id = id;
}

void		add_path(t_paths **total, t_path *new, t_info info)
{
	t_paths	*all;
	int		i;

	all = *total;
	i = 1;
	id_path(new, info);
	all->last->next = new;
	all->last = new;
	while (i < new->length - 1)
	{
		new->path[i]->used = 1;
		i++;
	}
	all->last->next = NULL;
	all->last->found = 0;
	all->count++;
}
