/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel_room_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:44:12 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/11 21:30:12 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room		**cancel_edge(t_paths *all_paths, t_path *sp, int i)
{
	t_path	*tmp;
	t_room	**out;
	int		j;

	out = (t_room**)malloc(sizeof(t_room*) * 1);
	out[0] = NULL;
	tmp = all_paths->first;
	while (tmp != NULL)
	{
		j = 0;
		while (j <= i)
		{
			if (tmp->path[j] != sp->path[j])
				break ;
			j++;
		}
		if (j == i + 1)
		{
			if (tmp->path[j] != NULL)
				out = join(out, gen_used(tmp->path[i], tmp->path[j]), 0, 0);
		}
		tmp = tmp->next;
	}
	return (out);
}

t_room		**cancel_nodes(t_path *sp, int i)
{
	t_room	**out;
	int		j;

	j = 0;
	out = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	while (j < i)
	{
		out[j] = sp->path[j];
		j++;
	}
	out[i] = NULL;
	return (out);
}
