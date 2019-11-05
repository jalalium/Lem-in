/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:05:36 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/23 21:46:30 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		not_used(t_room **used, t_room *node1, t_room *node2)
{
	int i;

	i = 0;
	while (used[i + 1] != NULL)
	{
		if ((node1 == used[i] && node2 == used[i + 1])
			|| (node1 == used[i + 1] && node2 == used[i]))
			return (0);
		i += 1;
	}
	return (1);
}

t_room	**join(t_room **one, t_room **two, int i, int j)
{
	int		k;
	t_room	**out;

	while (one[i] != NULL)
		i++;
	while (two[j] != NULL)
		j++;
	out = (t_room**)malloc(sizeof(t_room*) * (i + j + 1));
	k = 0;
	while (k < i)
	{
		out[k] = one[k];
		k++;
	}
	while (k < i + j)
	{
		out[k] = two[k - i];
		k++;
	}
	out[i + j] = NULL;
	free(one);
	free(two);
	return (out);
}

t_room	**gen_used(t_room *a, t_room *b)
{
	t_room	**used;

	used = (t_room**)malloc(sizeof(t_room*) * 3);
	used[0] = a;
	used[1] = b;
	used[2] = NULL;
	return (used);
}

void	print_all(t_info *info)
{
	int	i;

	i = 0;
	while (info->file[i])
	{
		ft_putstr(info->file[i]);
		ft_putchar('\n');
		i++;
	}
	i = 0;
	ft_putchar('\n');
	while (++i <= info->ant)
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr(info->end->name);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
