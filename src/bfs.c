/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:49:12 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/18 14:13:45 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		put_dist(t_queue **lst, t_room **child, int *d)
{
	int	i;

	i = -1;
	while (child[++i])
		if (child[i]->vis == 0)
		{
			add_to_queue(lst, child[i], (*lst)->room);
			child[i]->dist = child[i]->parent->dist + 1;
			*d = (*d > child[i]->dist) ? *d : child[i]->dist;
			child[i]->vis = 1;
		}
}

t_queue		*bfs(t_info *info)
{
	t_queue	*lst;
	t_queue	*head;
	int		d;

	unmark_avl(info->root);
	lst = NULL;
	add_to_queue(&lst, info->start, NULL);
	lst->room->vis = 1;
	head = lst;
	d = 0;
	lst->room->dist = 0;
	while (lst != NULL)
	{
		put_dist(&lst, lst->room->child, &d);
		lst = lst->next;
	}
	lst = head;
	getcord(&head, d);
	return (head);
}

void		print_nodes(t_queue *lst, t_info *info)
{
	int	i;

	i = 50 - pow((int)log2(info->room_nb), 1.5);
	while (lst != NULL)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putstr(lst->room->name);
		ft_putchar(' ');
		ft_putnbr(lst->room->x);
		ft_putchar(' ');
		ft_putnbr(lst->room->y);
		ft_putchar(' ');
		if (lst->room == info->start)
			ft_putnbr(1);
		else
			ft_putnbr((lst->room == info->end) ? 2 : 0);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void		visu(t_info *info, t_paths *all)
{
	t_queue	*head;
	t_queue	*tmp;

	head = bfs(info);
	print_nodes(head, info);
	edges(&head);
	print_path(all->first);
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free_paths(all);
}
