/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:53:39 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/25 20:24:05 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	file_realloc(char ***file, int len)
{
	char	**temp;
	int		i;

	if (!(temp = (char **)malloc(sizeof(char*) * (len + 1))))
		error();
	temp[len] = NULL;
	i = -1;
	while ((*file)[++i])
		temp[i] = (*file)[i];
	free(*file);
	if (!(*file = (char **)malloc(sizeof(char *) * (len + 2))))
		error();
	i = -1;
	while (++i < len)
		(*file)[i] = temp[i];
	free(temp);
}

void	file_concat(t_info *info, char *line)
{
	char	**temp;
	int		len;

	temp = NULL;
	if ((len = ft_tablen(info->file)) > 0)
	{
		file_realloc(&info->file, len);
		info->file[len] = line;
		info->file[len + 1] = NULL;
	}
	else
	{
		info->file = (char **)malloc(sizeof(char *) * 2);
		info->file[0] = line;
		info->file[1] = NULL;
	}
}

void	read_input(t_info *info)
{
	char	*line;
	int		ret;

	if ((ret = get_next_line(0, &line)) == -1 ||
			(info->ant = ft_atoi(line)) <= 0 || info->ant > 1000000000)
		error();
	file_concat(info, line);
	if (parse_rooms(info, &line) == 0)
		error();
	if (parse_links(info, &line) == -1)
		error();
}
