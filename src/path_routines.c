/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:13:17 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/23 20:02:03 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		path_length(t_room *tmp, t_room *y)
{
	int i;

	i = 0;
	while (tmp != NULL)
	{
		i++;
		if (tmp->parent == NULL)
		{
			if (tmp != y)
				return (-1);
		}
		tmp = tmp->parent;
	}
	return (i);
}

t_path	*free_when_fail(t_path *path)
{
	free(path);
	return (NULL);
}

t_path	*output_path(t_room *x, t_room *y)
{
	int			i;
	t_path		*path;
	t_room		*tmp;
	t_room		**copy;

	path = (t_path*)malloc(sizeof(t_path) * 1);
	tmp = x;
	i = path_length(tmp, y);
	if (i == -1)
		return (free_when_fail(path));
	tmp = x;
	copy = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	tmp = x;
	i = 0;
	while (tmp != NULL)
	{
		copy[i] = tmp;
		i++;
		tmp = tmp->parent;
	}
	copy[i] = NULL;
	path->length = i;
	path->path = copy;
	return (path);
}
