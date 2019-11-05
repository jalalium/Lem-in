/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unmark_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 23:52:31 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/12 23:54:01 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	unmark_room(t_room *root)
{
	root->vis = 0;
	root->dist = 2147483647;
	root->parent = NULL;
	root->in_heap = 0;
	root->mark = 0;
	root->lheap = NULL;
	root->rheap = NULL;
	root->pheap = NULL;
}

void	unmark_avl(t_room *root)
{
	if (!root)
		return ;
	unmark_room(root);
	if (root->left)
		unmark_room(root->left);
	if (root->right)
		unmark_room(root->right);
	unmark_avl(root->left);
	unmark_avl(root->right);
}

void	unuse_room(t_room *root)
{
	root->used = 0;
}

void	unmark_path(t_room *root)
{
	if (!root)
		return ;
	unuse_room(root);
	if (root->left)
		unuse_room(root->left);
	if (root->right)
		unuse_room(root->right);
	unmark_path(root->left);
	unmark_path(root->right);
}
