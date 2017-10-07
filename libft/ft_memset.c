/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:02:34 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 09:11:20 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int tmp, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		((char*)str)[x] = (unsigned char)tmp;
		x++;
	}
	return (str);
}
