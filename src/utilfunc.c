/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:53:07 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/23 13:59:53 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		max(int l, int r)
{
	return (l > r ? l : r);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

int		free_tab(char **t)
{
	int	i;

	if (t != NULL)
	{
		i = 0;
		while (t[i] && t[i][0])
		{
			free(t[i]);
			i++;
		}
		free(t);
		t = NULL;
	}
	return (1);
}

void	free_path(t_path *abc)
{
	free(abc->path);
	free(abc->id);
	free(abc);
}

void	free_paths(t_paths *all)
{
	t_path *tmp;
	t_path *tmp2;

	tmp = all->first;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free_path(tmp);
		tmp = tmp2;
	}
	if (all->potential != NULL)
		free(all->potential);
	free(all);
}
