/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 13:30:12 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 20:10:14 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_coms(char *line, t_map *map, int *steps, char *w_command)
{
	(void)map;
	if (line && *line == '#')
	{
		if (*(line + 1) == '#')
		{
			if (*w_command || (*steps != 1 && (!ft_strcmp((line + 2), "start")
						|| !ft_strcmp((line + 2), "end"))))
				return (1);
			if (!(ft_strcmp((line + 2), "start")))
				*w_command = 1;
			else if (!(ft_strcmp((line + 2), "end")))
				*w_command = 2;
		}
		return (0);
	}
	if (line)
		return (1);
	return (-1);
}

int			check_ants(char *line, t_map *map, int *step, char *command)
{
	map->ants = is_pos_int(line);
	if (map->ants == -1 || map->ants == 0 || *command)
		return (1);
	(*step)++;
	return (0);
}

static int	check_coord(char *cp_line, t_room *room)
{
	int		i;

	i = 0;
	while (cp_line[i])
		i++;
	while (i > 0 && cp_line[i] != ' ')
		i--;
	if (!cp_line[i + 1] || (room->y = is_pos_int(&(cp_line[i + 1]))) == -1)
	{
		free(cp_line);
		free(room);
		return (1);
	}
	cp_line[i] = 0;
	while (i > 0 && cp_line[i] != ' ')
		i--;
	if (!cp_line[i + 1] || (room->x = is_pos_int(&(cp_line[i + 1]))) == -1)
	{
		free(cp_line);
		free(room);
		return (1);
	}
	cp_line[i] = 0;
	return (0);
}

static int	check_name(t_map *map, char *cp_line, t_room *room)
{
	int		error;
	char	**name_split;
	int		i;

	error = 0;
	i = -1;
	name_split = NULL;
	if (!*cp_line || *cp_line == 'L')
		error = 1;
	else if (!(name_split = ft_strsplit(cp_line, ' ')))
		error = -1;
	else
		while (name_split && name_split[++i])
			if (*(name_split[i]) == 'L')
				error = 1;
	if (error || !(room->name = ft_strdup(cp_line, 0)))
		error = error == 0 ? -1 : error;
	else if (append_room(room, map))
		error = 1;
	if (error)
		free(room);
	free(cp_line);
	ft_freetab(name_split);
	return (error);
}

int			check_room(char *line, t_map *map, int *step, char *command)
{
	t_room	*room;
	char	*cp;
	int		ret;

	(void)step;
	if (!(cp = ft_strdup(line, 0))
			|| !(room = (t_room*)malloc(sizeof(t_room))))
		return (-1);
	room->next = NULL;
	room->links = NULL;
	room->nb_recur = 0;
	room->params = NULL;
	if (check_coord(cp, room))
		return (1);
	if ((ret = check_name(map, cp, room)))
		return (ret);
	if (*command == 1)
		map->start = room;
	else if (*command == 2)
		map->end = room;
	*command = 0;
	return (0);
}
