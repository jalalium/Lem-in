/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:31:53 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/13 20:32:34 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*find(char *name, t_room *root)
{
	if (!root || !name)
		return (NULL);
	if (ft_strcmp(name, root->name) < 0)
		return (find(name, root->left));
	else if (ft_strcmp(name, root->name) > 0)
		return (find(name, root->right));
	else
		return (root);
}
