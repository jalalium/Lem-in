/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:57:29 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 19:36:02 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		already_chosen(t_room **chosen, t_room *inode)
{
	int i;

	i = 0;
	if (chosen == NULL)
		return (0);
	while (chosen[i] != NULL)
	{
		if (chosen[i] == inode)
			return (1);
		i++;
	}
	return (0);
}

int		path_len(t_room **chosen)
{
	int i;

	i = 0;
	while (chosen[i] != NULL)
		i++;
	return (i);
}

t_room	**choose(t_room **chosen, t_room *inode)
{
	int		i;
	t_room	**out;

	i = 0;
	if (chosen == NULL)
		i = 0;
	else
		i = path_len(chosen);
	out = (t_room**)malloc(sizeof(t_room*) * (i + 2));
	i = 0;
	if (chosen != NULL)
	{
		while (chosen[i] != NULL)
		{
			out[i] = chosen[i];
			i++;
		}
	}
	out[i] = inode;
	out[i + 1] = NULL;
	if (chosen != NULL)
		free(chosen);
	return (out);
}

int		repeated(int *pab, int inter, int *dp)
{
	int i;

	i = 0;
	while (i < inter)
	{
		if (pab[i] != 0)
		{
			dp[pab[i]]++;
			if (dp[pab[i]] > 1)
				return (1);
		}
		i++;
	}
	return (0);
}
