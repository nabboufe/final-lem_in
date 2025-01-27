/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:07:20 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 19:40:51 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lem_in.h"

void	free_queue(t_queue *queue)
{
	t_queue	*tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}

void	free_links(t_link *link)
{
	t_link	*tmp;

	while (link)
	{
		tmp = link->next;
		link->room_dest = NULL;
		free(link);
		link = NULL;
		link = tmp;
	}
}

void	free_hash_tab(t_map *map)
{
	int		i;
	t_room	*tmp;
	t_room	*room;

	i = -1;
	while (++i < T_SIZE)
	{
		if (map->hash_tab[i])
		{
			room = map->hash_tab[i];
			while (room)
			{
				tmp = room->next;
				free(room->name);
				free_links(room->links);
				free(room);
				room = NULL;
				room = tmp;
			}
		}
		map->hash_tab[i] = NULL;
	}
}

void	free_room(t_room *room)
{
	t_link	*current_link;
	t_link	*tmp;

	while (room->params)
		param_next(&(room->params));
	current_link = room->links;
	while (current_link)
	{
		tmp = current_link;
		current_link = current_link->next;
		free(tmp);
	}
	free(room->name);
	free(room);
}

void	free_map(t_map *map)
{
	int		i;
	t_room	*current_room;
	t_room	*tmp;

	i = -1;
	if (!map)
		return ;
	while (++i < T_SIZE)
	{
		current_room = NULL;
		if (map->hash_tab[i])
			current_room = map->hash_tab[i];
		while (current_room)
		{
			tmp = current_room;
			current_room = current_room->next;
			free_room(tmp);
		}
	}
	if (map->best_paths)
		free_path(map->best_paths);
	if (map->hash_tab)
		free(map->hash_tab);
	free(map);
}
