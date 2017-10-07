/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:42:22 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 14:12:54 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	dstrlen(int n)
{
	size_t		psycho;

	psycho = 1;
	while (n /= 10)
		psycho++;
	return (psycho);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	cpy;

	len = dstrlen(n);
	cpy = n;
	if (n < 0)
	{
		cpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = cpy % 10 + '0';
	while (cpy /= 10)
		str[--len] = cpy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
