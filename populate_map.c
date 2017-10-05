/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:54:47 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/05 18:28:29 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     populate_map(int fd, char *line)
{
	int     y;
	int     i;
	int     cnt;
	int     flag;
	char    **map;

	i = 0;
	y = 0;
	cnt = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (flag == 0)
		{
			while(*line)
			{
				if(!ft_isspace(*line))
					cnt++;
				line++;
			}
			flag = 1;
		}
		i++;
	}
	printf("%d", cnt);
	i--;
	map = (char**)malloc(sizeof(char*) * (i + 1));
	while (y < i)
	{
		map[y] = (char*)malloc(sizeof(char) * (cnt + 1));
		y++;
	}
	return (0);
}
