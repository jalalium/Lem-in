/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:24:16 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/13 21:27:54 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		find_shortest(t_paths *all)
{
	t_path	*tmp;
	int		max;
	int		out;
	int		k;

	k = 1;
	out = -1;
	max = 2147483647;
	tmp = all->first;
	while (tmp != NULL)
	{
		if (tmp->length < max && tmp->found == 0)
		{
			max = tmp->length;
			out = k;
		}
		k++;
		tmp = tmp->next;
	}
	return (out);
}

void	find_index(int *stat, t_paths *all)
{
	if (stat[1] > all->count)
	{
		stat[2] = -1;
		return ;
	}
	stat[2] = find_shortest(all);
}
