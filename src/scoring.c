/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:28:51 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/25 20:08:04 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_empty(int *tab, int inter)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	while (i < inter)
	{
		if (tab[i] != 0)
		{
			count++;
		}
		i++;
	}
	return (count);
}

void	fill_length(int *test, int inter, t_paths *all, int *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < inter)
	{
		if (tab[i] != 0)
		{
			test[j] = find_kth_path(all, tab[i])->length - 1;
			j++;
		}
		i++;
	}
}

void	zero_set(int *score, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		score[i] = 0;
		i++;
	}
}

void	distribute_ants(int *score, int *test, int ants, int count)
{
	int i;
	int j;

	while (ants)
	{
		j = 0;
		i = 0;
		while (j < count)
		{
			if (test[j] + score[j] < test[i] + score[i])
				i = j;
			j++;
		}
		score[i]++;
		ants--;
	}
}

int		*scoring(t_paths *all, int *tab, int inter, int ants)
{
	int count;
	int *test;
	int *score;
	int	j;
	int k;

	count = count_empty(tab, inter);
	test = (int*)malloc(sizeof(int) * count);
	score = (int*)malloc(sizeof(int) * (count + 2));
	fill_length(test, inter, all, tab);
	zero_set(score, count);
	distribute_ants(score, test, ants, count);
	j = 0;
	k = 0;
	while (j < count)
	{
		if (test[j] + score[j] - 1 > k)
			k = test[j] + score[j] - 1;
		j++;
	}
	free(test);
	score[count] = k;
	score[count + 1] = -1;
	return (score);
}
