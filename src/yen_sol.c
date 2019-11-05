/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yen_sol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:56:12 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/25 20:13:08 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		**init_tabs(int **tab, int dummy)
{
	tab = (int**)malloc(sizeof(int*) * 4);
	tab[0] = (int*)malloc(sizeof(int) * dummy);
	zero_set(tab[0], dummy);
	tab[1] = (int*)malloc(sizeof(int) * dummy);
	tab[2] = (int*)malloc(sizeof(int) * dummy);
	return (tab);
}

void	update_sol(t_info info, t_paths *all, int **tab, int *sco)
{
	int ll;
	int i;

	ll = 0;
	tab[3] = scoring(all, tab[0], 5, info.ant);
	while (tab[3][ll] != -1)
		ll++;
	if (tab[3][ll - 1] < *sco)
	{
		*sco = tab[3][ll - 1];
		ll = 0;
		i = 0;
		while (i < 5)
		{
			tab[1][i] = tab[0][i];
			if (tab[1][i] != 0)
			{
				tab[2][i] = tab[3][ll];
				ll++;
			}
			i++;
		}
	}
	free(tab[3]);
}

void	select_winners(t_paths *all, int **tab)
{
	int		i;
	t_path	*tmp;

	i = 0;
	while (i < 5)
	{
		if (tab[1][i] != 0)
		{
			tmp = find_kth_path(all, tab[1][i]);
			tmp->found = 1;
			tmp->ants = tab[2][i];
		}
		i++;
	}
}

void	free_tabs(int **tab)
{
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
}

t_paths	*find_solution(t_info info, t_paths *all)
{
	int	score;
	int	**tab;
	int	r;

	score = 2147483647;
	tab = NULL;
	tab = init_tabs(tab, 5);
	while (1)
	{
		tab[0][5 - 1]++;
		r = carry_over(&tab[0], 5, all->count);
		if (r == 1)
			break ;
		if (r != 2)
			if (check_combination(tab[0], all, 5))
				update_sol(info, all, tab, &score);
	}
	select_winners(all, tab);
	free_tabs(tab);
	return (all);
}
