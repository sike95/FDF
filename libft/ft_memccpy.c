/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:14:06 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 09:23:44 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*psycho;
	size_t	x;

	x = -1;
	psycho = dest;
	while (++x < n)
	{
		*(psycho + x) = *((unsigned char *)src + x);
		if (*((unsigned char *)src + x) == (unsigned char)c)
			return (dest + x + 1);
	}
	return (NULL);
}
