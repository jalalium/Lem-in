/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:32:15 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 20:06:07 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	choose_p(int **tab, int *stat, t_info info, t_paths *all)
{
	find_kth_path(all, stat[2])->found = 1;
	tab[0][stat[1]] = stat[2];
	stat[1]++;
	tab[1] = scoring(all, tab[0], info.end->children, info.ant);
	update_last(tab, stat);
}
