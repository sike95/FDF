/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:24:30 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 14:01:25 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const char	*sc;
	size_t		x;

	sc = (const char *)src;
	x = -1;
	while (++x < n)
		if (*(sc + x) == (char)c)
			return ((void *)sc + x);
	return (NULL);
}
