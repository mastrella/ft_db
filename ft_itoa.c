/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 07:19:16 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/18 00:27:54 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static int	ft_ilength(int n)
{
	int mod;
	int	len;

	mod = n;
	len = 0;
	if (mod <= 0)
		len++;
	while (mod != 0)
	{
		mod = mod / 10;
		len++;
	}
	return (len);
}

static int		ft_isnegative(long mod)
{
	size_t	neg;

	if (mod < 0)
	{
		neg = 1;
		mod = mod * (-1);
	}
	else
		neg = 0;
	return (neg);
}

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	neg;
	long	mod;
	char	*value;

	mod = n;
	neg = ft_isnegative(mod);
	if (n < 0)
		mod = -mod;
	len = ft_ilength(n);
	value = ft_strnew(len);
	if (!value)
		return (NULL);
	value[len--] = '\0';
	if (mod == 0)
		value[len] = '0';
	while (mod != 0)
	{
		value[len] = (mod % 10) + '0';
		mod = mod / 10;
		len--;
	}
	if (neg == 1)
		value[len--] = '-';
	return (value);
}
