/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:37:47 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 09:41:55 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int x;
	int neg;
	int nbr;

	x = 0;
	neg = 0;
	nbr = 0;
	while ((str[x] == ' ') || (str[x] == '\t') || (str[x] == '\n')
			|| (str[x] == '\v') || (str[x] == '\f') || (str[x] == '\r'))
		x++;
	if (str[x] == 45)
		neg = 1;
	if ((str[x] == 45) || (str[x] == 43))
		x++;
	while ((str[x] >= 48) && (str[x] <= 57))
	{
		nbr *= 10;
		nbr += ((int)str[x] - 48);
		x++;
	}
	if (neg)
		return (-nbr);
	else
		return (nbr);
}
