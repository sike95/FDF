/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 08:24:12 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 12:43:46 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			x;

	x = -1;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (++x < n && *(s1c + x) == *(s2c + x))
		;
	if (x == n)
		return (0);
	return (*(s1c + x) - *(s2c + x));
}
