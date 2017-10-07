/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:52:16 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/07 13:51:19 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *sr, int c)
{
	char	*death;

	death = (char *)sr + ft_strlen(sr);
	while (*death != c)
	{
		if (death == sr)
		{
			return (0);
		}
		death--;
	}
	return (death);
}
