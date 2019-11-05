/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:36:16 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/25 19:29:36 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_line(char *name, int ant)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void	move_sub(t_path *path, t_room *prev, int j, int *end)
{
	path->path[j]->ant = prev->ant;
	print_line(path->path[j]->name, prev->ant);
	prev->ant = 0;
	*end = 1;
}

int		move(t_info *info, t_path *path, int *i, int *end)
{
	int		j;
	t_room	*prev;

	j = path->length - 1;
	while (j > 0)
	{
		prev = path->path[j - 1];
		if (prev != path->path[0])
		{
			if (prev->ant != 0)
				move_sub(path, prev, j, end);
		}
		else if (*i <= info->ant && path->done < path->ants)
		{
			path->path[j]->ant = *i;
			print_line(path->path[j]->name, *i);
			*i += 1;
			path->done++;
			*end = 1;
		}
		j--;
	}
	return (0);
}

void	print_file(t_info *info)
{
	int	i;

	i = 0;
	while (info->file[i])
	{
		ft_putstr(info->file[i++]);
		ft_putchar('\n');
	}
}

void	result(t_info *info, t_paths *all, int i, int end)
{
	t_path *path;
	t_path *path2;

	path = all->first;
	print_file(info);
	while (path != NULL)
	{
		path->done = 0;
		path = path->next;
	}
	while (end)
	{
		end = 0;
		path = all->first;
		ft_putchar('\n');
		while (path != NULL)
		{
			if (path->found == 1)
				move(info, path, &i, &end);
			path2 = path->next;
			path = path2;
		}
	}
	free_paths(all);
}
