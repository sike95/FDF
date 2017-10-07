/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:02:37 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 10:30:11 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		x;

	x = -1;
	while (++x < n)
		if (*(src + x))
			*(dest + x) = *(src + x);
		else
			while (x < n)
				*(dest + x++) = '\0';
	return (dest);
}
