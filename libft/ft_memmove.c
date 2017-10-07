/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:17:25 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/16 08:16:21 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*srcc;
	char		*dst;

	srcc = src;
	dst = dest;
	if (dst <= srcc || srcc >= (dst + n))
	{
		while (n)
		{
			*dst++ = *srcc++;
			n--;
		}
	}
	else
	{
		srcc = srcc + n - 1;
		dst = dst + n - 1;
		while (n)
		{
			*dst-- = *srcc--;
			n--;
		}
	}
	return (dest);
}
