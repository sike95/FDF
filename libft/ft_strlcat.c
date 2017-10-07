/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 10:59:24 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 10:41:06 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t		x;
	int			y;
	size_t		dst;
	size_t		srcc;

	x = ft_strlen(dest);
	y = 0;
	dst = ft_strlen(dest);
	srcc = ft_strlen(src);
	if (s < dst + 1)
		return (srcc + s);
	if (s > dst + 1)
	{
		while (x < s - 1)
			*(dest + x++) = *(src + y++);
		*(dest + x) = '\0';
	}
	return (dst + srcc);
}
