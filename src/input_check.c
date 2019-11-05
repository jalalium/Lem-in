/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:25:09 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/06/17 14:25:33 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_comment(char *line)
{
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			return (1);
		else if (!ft_strcmp(line, "##end"))
			return (2);
		else
			return (0);
	}
	else
		return (-1);
}

void	insert_room(t_info *info, char **tab, int stat)
{
	t_room	*elem;
	t_tuple	coord;

	elem = find(tab[0], info->root);
	coord = (t_tuple){ft_atoi(tab[1]), ft_atoi(tab[2]), stat};
	if (elem != NULL)
	{
		elem->x = coord.x;
		elem->y = coord.y;
		elem->stat = coord.stat;
	}
	else
		info->root = avl_insert(tab[0], coord, info->root, info);
}

void	manage_error(char **tab, char **line)
{
	free_tab(tab);
	free(*line);
	error();
}

void	ajouter_room(t_info *info, char **tab, int old)
{
	insert_room(info, tab, old);
	info->room_nb++;
}

int		check_nametag(char **tab)
{
	if (ft_tablen(tab) == 1 || tab[0][0] == 'L'
		|| ft_strchr(tab[0], '-') != NULL)
		return (1);
	return (0);
}
