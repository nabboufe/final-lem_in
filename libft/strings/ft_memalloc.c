/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: affect <affect@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:53:45 by affect            #+#    #+#             */
/*   Updated: 2020/03/13 14:54:52 by affect           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *addr;

	if (!(addr = (void *)malloc(size)))
		return (NULL);
	ft_bzero(addr, size);
	return (addr);
}