/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:09:22 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/25 20:46:25 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_room(t_room **node)
{
	t_room *t;

	t = *node;
	if (*node != NULL)
	{
		free(t->name);
		free(t->child);
		free(t);
		t = NULL;
	}
}

void	free_avl(t_room **root)
{
	if (*root != NULL)
	{
		free_avl(&(*root)->left);
		free_avl(&(*root)->right);
		free_room(root);
		*root = NULL;
	}
}

/*
** get the height of a node
*/

int		height(t_room *root)
{
	if (root == NULL)
		return (-1);
	else
		return (root->height);
}

void	init(t_info *info)
{
	info->ant = 0;
	info->path = NULL;
	info->file = NULL;
	info->root = NULL;
	info->room_nb = 0;
}
