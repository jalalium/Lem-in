/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:17:33 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/23 20:01:54 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_paths		*init_ypaths(t_info info, t_path *sp)
{
	t_paths	*all_paths;

	all_paths = (t_paths*)malloc(sizeof(t_paths) * 1);
	all_paths->count = 0;
	all_paths->first = sp;
	all_paths->potential = NULL;
	all_paths->last = sp;
	add_path(&all_paths, sp, info);
	return (all_paths);
}

void		free_aux(t_path *tmp)
{
	free(tmp->path);
	free(tmp);
}

void		update_potential(t_info info, t_paths *all_paths, t_path *ac_path)
{
	int		i;
	t_room	**nodes;
	t_room	**used;
	t_path	*tmp;

	i = -1;
	while (++i < ac_path->length - 1)
	{
		used = cancel_edge(all_paths, ac_path, i);
		nodes = (i > 0 ? cancel_nodes(ac_path, i) : NULL);
		tmp = dijkstra_three(info, used, nodes, ac_path->path[i]);
		if (tmp != NULL)
		{
			tmp = concat(ac_path, tmp, i);
			if (all_paths->potential == NULL)
				add_qpath(&all_paths, tmp);
			else
			{
				if (all_paths->potential->length >= tmp->length)
					update_qpath(&all_paths, tmp);
				else
					free_aux(tmp);
			}
		}
	}
}

t_paths		*find_k_paths(t_info info, t_path *sp, int i)
{
	t_path	*ac_path;
	t_paths	*all_paths;

	all_paths = init_ypaths(info, sp);
	ac_path = all_paths->first;
	i = 0;
	while (all_paths->count < 30)
	{
		update_potential(info, all_paths, ac_path);
		if (all_paths->potential != NULL)
			add_path(&all_paths, all_paths->potential, info);
		else
			break ;
		all_paths->potential = NULL;
		ac_path = ac_path->next;
	}
	return (all_paths);
}
