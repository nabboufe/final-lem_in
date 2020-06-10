/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:02:08 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 21:31:39 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	quit(t_parser *tab_parser, t_map *map, char *input,
		int error_type)
{
	if (tab_parser)
		free(tab_parser);
	if (input)
		free(input);
	if (map)
		free_map(map);
	if (error_type == 1)
		write(2, "ERROR\n", 6);
	else if (error_type == -1)
		write(2, "Malloc Error\n", 13);
	return (error_type == -1 ? 1 : 0);
}

int			main(void)
{
	t_parser		*tab_parser;
	t_map			*map;
	char			*line;
	char			*input;

	line = NULL;
	map = NULL;
	tab_parser = NULL;
	input = ft_strnew(0);
	if (!(tab_parser = init_parser(tab_parser))
			|| !(map = initialize_map(map)))
		return (quit(tab_parser, map, input, -1));
	parser(map, tab_parser, line, &input);
	if (map->ants == -1 || !map->start || !map->end)
		return (quit(tab_parser, map, input, 1));
	if (append_param(map->start, NULL, 0) || find_best_paths(map, map->start))
		return (quit(tab_parser, map, input, -1));
	if (!map->best_paths)
		return (quit(tab_parser, map, input, 1));
	write(1, input, ft_strlen(input));
	display_instructions(map, map->best_paths, map->best_steps);
	return (quit(tab_parser, map, input, 0));
}
