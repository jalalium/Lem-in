/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:40:11 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/14 23:14:03 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** perform a rotation between a root and its left child
** note: call s_rotate_left only if the root has a left child
*/

static t_room	*s_rotate_left(t_room *r)
{
	t_room	*t;

	t = NULL;
	t = r->left;
	r->left = t->right;
	t->right = r;
	r->height = max(height(r->left), height(r->right)) + 1;
	t->height = max(height(t->left), height(r->right)) + 1;
	return (t);
}

/*
** perform a rotation between a root and its right child
** note: call s_rotate_left only if the root has a right child
*/

static t_room	*s_rotate_right(t_room *r)
{
	t_room	*t;

	t = NULL;
	t = r->right;
	r->right = t->left;
	t->left = r;
	r->height = max(height(r->left), height(r->right)) + 1;
	t->height = max(height(t->left), height(r->right)) + 1;
	return (t);
}

/*
** perform the left-right double rotation
*/

static t_room	*d_rotate_left(t_room *r)
{
	r->left = s_rotate_right(r->left);
	return (s_rotate_left(r));
}

/*
** perform the right-left double rotation
*/

static t_room	*d_rotate_right(t_room *r)
{
	r->right = s_rotate_left(r->right);
	return (s_rotate_right(r));
}

t_room			*avl_insert(char *name, t_tuple data, t_room *root, t_info *h)
{
	if (root == NULL)
	{
		root = create_room(name, data.x, data.y, data.stat);
		if (data.stat == 1)
			h->start = root;
		else if (data.stat == 2)
			h->end = root;
	}
	else if (ft_strcmp(name, root->name) < 0)
	{
		root->left = avl_insert(name, data, root->left, h);
		if (height(root->left) - height(root->right) == 2)
			root = (ft_strcmp(name, root->left->name) < 0) ?
				s_rotate_left(root) : d_rotate_left(root);
	}
	else if (ft_strcmp(name, root->name) > 0)
	{
		root->right = avl_insert(name, data, root->right, h);
		if (height(root->right) - height(root->left) == 2)
			root = (ft_strcmp(name, root->right->name) > 0) ?
				s_rotate_right(root) : d_rotate_right(root);
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return (root);
}
