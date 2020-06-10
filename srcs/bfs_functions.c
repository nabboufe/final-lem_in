/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:24:45 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 19:39:38 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_link	*find_link(t_room *room, t_room *room_dest)
{
	t_link *current_link;

	current_link = room->links;
	while (current_link)
	{
		if (current_link->room_dest == room_dest)
			return (current_link);
		current_link = current_link->next;
	}
	return (NULL);
}

int		verif_launch_recur(t_queue *queue, t_map *map, t_link *current_link)
{
	t_queue *current;
	t_queue	*path;

	if (!current_link || current_link->room_dest->nb_recur > 1)
		return (1);
	if (!(path = find_bfs_path(map, queue->room)))
		return (1);
	current = path;
	while (current->next)
	{
		if (current->room == queue->room\
				&& current->next->room == current_link->room_dest)
		{
			free_queue(path);
			return (1);
		}
		current = current->next;
	}
	free_queue(path);
	return (0);
}

t_queue	*find_bfs_path(t_map *map, t_room *end)
{
	t_room	*room;
	t_param	*current;
	t_queue	*current_path;
	t_queue	*path;

	room = end;
	path = NULL;
	while (room != map->start)
	{
		current = room->params;
		current_path = path;
		while (current_path)
		{
			if (current_path->room == room)
				current = current->next;
			current_path = current_path->next;
		}
		if (append_start_queue(&path, room))
			return (NULL);
		room = current->prev;
	}
	if (append_start_queue(&path, room))
		return (NULL);
	return (path);
}

void	reset_visited(t_queue **queue)
{
	t_param	*tmp;
	t_queue	*tmp_queue;

	while (*queue)
	{
		tmp = (*queue)->room->params;
		(*queue)->room->params = (*queue)->room->params->next;
		free(tmp);
		tmp_queue = *queue;
		*queue = (*queue)->next;
		free(tmp_queue);
	}
}
