/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:23:42 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 19:39:14 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	initialize_tab_ants(t_queue **tab_ants, int ants)
{
	int		i;

	i = 0;
	while (i < ants)
	{
		tab_ants[i] = NULL;
		i++;
	}
}

static void	print_instructions(t_queue **tab_ants, int sent_ants)
{
	int		current_ant;
	int		i;

	current_ant = -1;
	i = 0;
	while (++current_ant < sent_ants)
	{
		if (tab_ants[current_ant] && tab_ants[current_ant]->room)
		{
			if (i)
				write(1, " ", 1);
			write(1, "L", 1);
			ft_putnbr(current_ant + 1);
			write(1, "-", 1);
			write(1, tab_ants[current_ant]->room->name,
				ft_strlen(tab_ants[current_ant]->room->name));
			i++;
		}
	}
	write(1, "\n", 1);
}

static void	refresh_tab_ants(t_queue **tab_ants, t_path *paths, int *sent_ants)
{
	int		current_ant;
	int		nb_path;

	current_ant = -1;
	while (++current_ant < *sent_ants)
		if (tab_ants[current_ant])
			tab_ants[current_ant] = tab_ants[current_ant]->next;
	nb_path = -1;
	while (paths[++nb_path].path)
	{
		if (paths[nb_path].ants)
		{
			tab_ants[*sent_ants] = paths[nb_path].path->next;
			paths[nb_path].ants = paths[nb_path].ants - 1;
			(*sent_ants)++;
		}
	}
}

int			display_instructions(t_map *map, t_path *paths, int steps)
{
	t_queue	**tab_ants;
	int		nb_step;
	int		sent_ants;

	if (!(tab_ants = (t_queue**)malloc(sizeof(t_queue*) * (map->ants))))
		return (-1);
	initialize_tab_ants(tab_ants, map->ants);
	nb_step = -1;
	sent_ants = 0;
	while (++nb_step < steps)
	{
		refresh_tab_ants(tab_ants, paths, &sent_ants);
		print_instructions(tab_ants, sent_ants);
	}
	free(tab_ants);
	return (0);
}
