/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_combination.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:27:56 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/25 19:59:26 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	verify_comb(t_room ***chosen, t_paths *all, int z, int *bad)
{
	t_path	*tmp;
	int		l;

	tmp = find_kth_path(all, z);
	if (tmp != NULL)
	{
		l = 1;
		while (l < tmp->length - 1)
		{
			if (already_chosen(*chosen, tmp->path[l]) == 1)
			{
				*bad = 0;
				break ;
			}
			else
				*chosen = choose(*chosen, tmp->path[l]);
			l++;
		}
	}
	else
		*bad = 0;
}

int		check_combination(int *tab, t_paths *all, int dummy)
{
	t_room	**chosen;
	int		z;
	int		bad;

	chosen = (t_room**)malloc(sizeof(t_room*) * 1);
	chosen[0] = NULL;
	z = 0;
	while (z < dummy)
	{
		bad = 1;
		if (tab[z] != 0)
			verify_comb(&chosen, all, tab[z], &bad);
		if (bad == 0)
		{
			free(chosen);
			return (0);
		}
		z++;
	}
	free(chosen);
	return (1);
}
