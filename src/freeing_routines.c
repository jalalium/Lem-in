/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:41:13 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/23 19:57:03 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		free_tab_stat(int **tab, int *stat)
{
	int x;

	x = stat[0];
	free(tab[0]);
	free(tab);
	free(stat);
	return (x);
}

void	despair(t_paths *all, int x, int *tab)
{
	free(tab);
	find_kth_path(all, x)->found = 2;
}
