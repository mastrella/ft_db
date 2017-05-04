/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:18:45 by mmastrel          #+#    #+#             */
/*   Updated: 2016/11/23 07:18:23 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	x = (unsigned char*)b;
	while (i < len)
	{
		x[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
