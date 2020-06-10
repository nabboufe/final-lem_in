/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 09:12:58 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/10 19:43:53 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			param_next(t_param **params)
{
	t_param	*tmp;

	if (!params || !*params)
		return ;
	tmp = *params;
	*params = (*params)->next;
	free(tmp);
}

int				append_param(t_room *room, t_room *prev, int depth)
{
	t_param	*new;

	if (!(new = (t_param*)malloc(sizeof(t_param))))
		return (1);
	new->depth = depth;
	new->prev = prev;
	new->next = room->params;
	room->params = new;
	return (0);
}
