/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 10:35:11 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/07 13:48:30 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t p)
{
	char	*psycho;

	psycho = dest;
	while (*psycho != '\0')
	{
		psycho++;
	}
	while (*src != '\0' && p > 0)
	{
		*psycho = *src;
		psycho++;
		src++;
		p--;
	}
	*psycho = '\0';
	return (dest);
}
