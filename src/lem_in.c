/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 22:07:21 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/24 19:09:01 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_paths		*even_and_odd(t_info info, int i)
{
	t_path	*out;
	t_paths	*ot;

	out = NULL;
	ot = NULL;
	if (i == 1)
	{
		out = dijkstra_len(info);
		ot = find_and_erase(info, out, 0);
	}
	else
	{
		out = dijkstra_inter(info);
		ot = find_and_erase(info, out, 1);
	}
	return (ot);
}

t_paths		*binary_heuristic(t_info info)
{
	t_paths *one;
	t_paths *two;

	unmark_path(info.root);
	one = even_and_odd(info, 1);
	one->potential = NULL;
	unmark_path(info.root);
	two = even_and_odd(info, 2);
	two->potential = NULL;
	if (choose_sol(info, one) < choose_sol(info, two))
	{
		free_paths(two);
		return (one);
	}
	free_paths(one);
	return (two);
}

t_paths		*yen_or_remove(t_info info)
{
	t_path *tmp;

	if (info.room_nb < 50)
	{
		tmp = dijkstra_len(info);
		return (find_solution(info, find_k_paths(info, tmp, 0)));
	}
	else
		return (binary_heuristic(info));
}

int			check_errors(t_info info)
{
	t_path *p;

	p = NULL;
	if (info.start == NULL || info.end == NULL)
		return (-1);
	if (info.start->name == NULL || info.end->name == NULL)
		return (-1);
	if (info.end->children == 0 || info.start->children == 0)
		return (-1);
	if ((p = dijkstra_len(info)) == NULL)
		return (-1);
	if (p->path[0] == info.start && p->path[1] == info.end)
	{
		print_all(&info);
		free(p->path);
		free(p);
		return (1);
	}
	free(p->path);
	free(p);
	return (0);
}

int			main(int argc, char **argv)
{
	t_info		info;
	int			r;

	init(&info);
	read_input(&info);
	r = check_errors(info);
	if (r == 0)
	{
		if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
			visu(&info, yen_or_remove(info));
		else
			result(&info, yen_or_remove(info), 1, 1);
	}
	else if (r == -1)
		ft_putstr("ERROR\n");
	free_tab(info.file);
	free_avl(&info.root);
	return (0);
}
