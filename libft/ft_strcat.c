/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 10:22:05 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/07 13:46:20 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t		death;
	int			l;

	l = 0;
	death = 0;
	while (dest[death])
		death++;
	while (src[l] != '\0')
	{
		dest[death + l] = src[l];
		l++;
	}
	dest[death + l] = '\0';
	return (dest);
}
