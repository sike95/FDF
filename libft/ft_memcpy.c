/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:23:08 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 09:03:58 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t x)
{
	size_t	d;
	char	*tmp;
	char	*t;

	tmp = str1;
	t = (char *)str2;
	d = -1;
	while (++d < x)
		*(tmp + d) = *(t + d);
	return (str1);
}
