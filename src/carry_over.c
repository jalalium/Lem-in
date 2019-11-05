/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carry_over.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:02:20 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/16 19:49:21 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		fr(int *dp, int i)
{
	free(dp);
	return (i);
}

int		carry_over(int **tab, int inter, int count)
{
	int i;
	int *pab;
	int	*dp;

	i = 0;
	dp = (int*)malloc(sizeof(int) * (count + 1));
	zero_set(dp, count + 1);
	pab = *tab;
	if (pab[0] == 1 && pab[1] == 2 && pab[2] == 3 && pab[3] == 4 && pab[4] == 5)
		return (fr(dp, 1));
	while (--inter >= 0)
		if (pab[inter] > count)
		{
			if (inter == 0)
				return (1);
			pab[inter - 1]++;
			pab[inter] = 0;
		}
	if (repeated(pab, inter, dp))
		return (fr(dp, 2));
	return (fr(dp, 0));
}
