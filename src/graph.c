/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:17:28 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/14 23:16:58 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*create_room(char *name, int x, int y, int stat)
{
	t_room	*new_elem;

	if (!(new_elem = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	new_elem->name = ft_strdup(name);
	new_elem->x = x;
	new_elem->ant = 0;
	new_elem->y = y;
	new_elem->stat = stat;
	new_elem->child = (t_room **)malloc(sizeof(t_room*));
	new_elem->child[0] = NULL;
	new_elem->left = NULL;
	new_elem->right = NULL;
	new_elem->children = 0;
	return (new_elem);
}

int		add_edge(t_room *parent, t_room *child)
{
	t_room **copy;
	size_t i;
	size_t j;

	i = 0;
	j = -1;
	while (parent->child[i] != NULL)
		i++;
	if (!(copy = (t_room**)malloc(sizeof(t_room*) * (i + 1))))
		return (-1);
	while (++j < i)
		copy[j] = parent->child[j];
	copy[j] = NULL;
	free(parent->child);
	if (!(parent->child = (t_room **)malloc(sizeof(t_room*) * (j + 2))))
		return (-1);
	i = -1;
	while (++i < j)
		parent->child[i] = copy[i];
	free(copy);
	parent->child[i++] = child;
	parent->child[i] = NULL;
	parent->children++;
	return (1);
}
