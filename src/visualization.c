/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:36:13 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/18 13:36:21 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_queue(t_queue **head, t_room *room, t_room *parent)
{
	t_queue	*new;
	t_queue	*tmp;

	new = (t_queue *)malloc(sizeof(t_queue));
	new->room = room;
	new->room->parent = parent;
	new->next = NULL;
	tmp = *head;
	if (tmp == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	get_y_coord(t_queue **elem, int i, int c)
{
	int	y;

	y = 1;
	while (*elem != NULL && (*elem)->room->dist == i)
	{
		(*elem)->room->y = y * c;
		y++;
		*elem = (*elem)->next;
	}
}

void	getcord(t_queue **head, int depth)
{
	int		x;
	int		count;
	int		i;
	t_queue	*elem;
	t_queue	*before;

	x = 5;
	i = 0;
	elem = *head;
	while (elem != NULL)
	{
		count = 0;
		before = elem;
		while (elem != NULL && elem->room->dist == i)
		{
			elem->room->x = x;
			elem = elem->next;
			count++;
		}
		elem = before;
		get_y_coord(&elem, i, 1300 / (count + 1));
		i++;
		x += 2350 / (depth);
	}
}

void	edges(t_queue **head)
{
	t_queue	*elem;
	int		i;

	elem = *head;
	ft_putstr("----------------\n");
	while (elem)
	{
		ft_putstr(elem->room->name);
		ft_putchar(' ');
		i = -1;
		while (elem->room->child[++i])
		{
			ft_putstr(elem->room->child[i]->name);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		elem = elem->next;
	}
	ft_putstr("----------------\n");
}

void	print_path(t_path *path)
{
	int i;

	while (path != NULL)
	{
		if (path->found == 1)
		{
			i = 0;
			while (i < path->length)
			{
				ft_putstr(path->path[i]->name);
				ft_putchar(' ');
				i++;
			}
			ft_putchar('\n');
		}
		path = path->next;
	}
}
