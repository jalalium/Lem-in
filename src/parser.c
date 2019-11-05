/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 00:01:46 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/23 14:00:24 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_rooms(t_info *info, char **line)
{
	char	**tab;
	int		ret;
	int		old;

	while ((ret = get_next_line(0, line)))
	{
		if (ret == -1 || ft_strlen(*line) < 1)
			error();
		if ((ret = check_comment(*line)) == -1)
		{
			tab = ft_strsplit(*line, ' ');
			if (check_nametag(tab))
				return (free_tab(tab));
			else if (ft_tablen(tab) != 3)
				manage_error(tab, line);
			else
				ajouter_room(info, tab, old);
			free_tab(tab);
			old = (old != 0 ? 0 : old);
		}
		else
			old = ret;
		file_concat(info, *line);
	}
	return (0);
}

int		insert_edge(t_info *info, char **tab)
{
	char	**t;
	t_room	*room1;
	t_room	*room2;

	t = ft_strsplit(tab[0], '-');
	if (ft_tablen(t) != 2)
	{
		free_tab(t);
		return (-1);
	}
	room1 = find(t[0], info->root);
	room2 = find(t[1], info->root);
	if (room1 != NULL && room2 != NULL)
	{
		add_edge(room1, room2);
		add_edge(room2, room1);
	}
	else
		error();
	return (free_tab(t));
}

int		parse_links(t_info *info, char **line)
{
	char	**tab;
	int		ret;

	ret = 0;
	while (1)
	{
		if (ret == -1 || ft_strlen(*line) < 1)
			error();
		if (check_comment(*line) == -1)
		{
			tab = ft_strsplit(*line, ' ');
			if (ft_tablen(tab) != 1 || insert_edge(info, tab) == -1)
			{
				free(*line);
				free_tab(tab);
				return (-1);
			}
			free_tab(tab);
		}
		file_concat(info, *line);
		if ((ret = get_next_line(0, line)) == 0)
			break ;
	}
	return (0);
}
