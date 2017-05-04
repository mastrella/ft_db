/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:14:06 by mmastrel          #+#    #+#             */
/*   Updated: 2016/11/23 07:14:08 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void*)malloc(size);
	if (!mem)
		return (NULL);
	return (ft_memset(mem, 0, size));
}
