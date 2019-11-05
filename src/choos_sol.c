/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:03:57 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/23 18:02:44 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		**init_tabz(int **tab, t_info info)
{
	tab = (int**)malloc(sizeof(int*) * 2);
	tab[0] = (int*)malloc(sizeof(int) * info.end->children);
	zero_set(tab[0], info.end->children);
	return (tab);
}

int		*init_stats(int *stat)
{
	stat = (int*)malloc(sizeof(int) * 4);
	stat[0] = 2147483647;
	stat[1] = 0;
	stat[2] = 3;
	return (stat);
}

void	update_last(int **tab, int *stat)
{
	int ll;

	ll = 0;
	while (tab[1][ll] != -1)
		ll++;
	stat[3] = ll;
}

void	update_solu(int **tab, int *stat, t_paths *all, t_info info)
{
	int p;

	p = 0;
	stat[0] = tab[1][stat[3] - 1];
	while (p < info.end->children)
	{
		if (tab[0][p] != 0)
			find_kth_path(all, tab[0][p])->ants = tab[1][p];
		p++;
	}
}

int		choose_sol(t_info info, t_paths *all)
{
	int			**tab;
	int			*stat;

	tab = NULL;
	stat = NULL;
	tab = init_tabz(tab, info);
	stat = init_stats(stat);
	while (1)
	{
		find_index(stat, all);
		if (stat[2] == -1)
			break ;
		choose_p(tab, stat, info, all);
		if (tab[1][stat[3] - 1] < stat[0])
			update_solu(tab, stat, all, info);
		else
		{
			despair(all, stat[2], tab[1]);
			break ;
		}
		free(tab[1]);
	}
	return (free_tab_stat(tab, stat));
}
