/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:27:14 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/07 13:52:07 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		x;
	int		y;
	int		z;
	int		death;

	if (!ft_strlen(little))
		return ((char *)big);
	x = -1;
	death = 0;
	while (*(big + ++x) && !death)
	{
		if (*(big + x) == *(little + 0))
		{
			y = 0;
			z = x;
			death = 1;
			while (*(little + y))
				if (*(little + y++) != *(big + z++))
					death = 0;
			if (death)
				return ((char *)big + x);
		}
	}
	return (NULL);
}
