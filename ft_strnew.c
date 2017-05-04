/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:13:55 by mmastrel          #+#    #+#             */
/*   Updated: 2016/11/23 07:13:53 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char*)ft_memalloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	return (s);
}
