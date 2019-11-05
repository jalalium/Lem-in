/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potential_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:47:35 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 19:41:35 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		add_qpath(t_paths **total, t_path *new)
{
	t_paths	*all;
	int		i;

	i = 0;
	all = *total;
	if (all->potential == NULL)
		all->potential = new;
}

void		update_qpath(t_paths **total, t_path *new)
{
	t_paths	*all;
	int		i;

	i = 0;
	all = *total;
	free(all->potential->path);
	free(all->potential);
	all->potential = new;
}
