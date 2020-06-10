/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:02:17 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 20:12:00 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_parser	*init_parser(t_parser *tab_parser)
{
	if (!(tab_parser = (t_parser*)malloc(sizeof(t_parser) * 4)))
		return (NULL);
	tab_parser[0].step = 0;
	tab_parser[0].f = &check_coms;
	tab_parser[1].step = 0;
	tab_parser[1].f = &check_ants;
	tab_parser[2].step = 1;
	tab_parser[2].f = &check_room;
	tab_parser[3].step = 2;
	tab_parser[3].f = &check_link;
	return (tab_parser);
}

t_map			*initialize_map(t_map *map)
{
	t_room	**hash_tab;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->ants = -1;
	map->start = NULL;
	map->end = NULL;
	map->best_steps = -1;
	map->best_paths = NULL;
	if (!(hash_tab = (t_room**)ft_memalloc(sizeof(t_room*) * T_SIZE)))
	{
		free(map);
		return (NULL);
	}
	map->hash_tab = hash_tab;
	return (map);
}
