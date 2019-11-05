/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:01:42 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/16 12:53:58 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path		*concat(t_path *sp, t_path *new, int n)
{
	t_path		*out;
	t_room		**lout;
	int			j;
	int			i;

	j = 0;
	out = (t_path*)malloc(sizeof(t_path) * 1);
	lout = (t_room**)malloc(sizeof(t_room*) * (new->length + n + 1));
	while (j < n)
	{
		lout[j] = sp->path[j];
		j++;
	}
	i = 0;
	while (i < new->length)
	{
		lout[j + i] = new->path[i];
		i++;
	}
	lout[new->length + n] = NULL;
	out->length = n + new->length;
	out->path = lout;
	free(new->path);
	free(new);
	return (out);
}
