/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_kth_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:44:56 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/13 21:45:12 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*find_kth_path(t_paths *all, int x)
{
	t_path	*tmp;
	int		k;

	tmp = all->first;
	k = 1;
	while (k < x)
	{
		k++;
		tmp = tmp->next;
	}
	return (tmp);
}
