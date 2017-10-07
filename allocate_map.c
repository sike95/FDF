/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 09:30:02 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/07 11:38:46 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_row_col		get_size(int fd)
{
	t_row_col  size;
	int		flag;
	int		i;
	int		cnt;
	char	**split;
	char	*line;

	i = 0;
	cnt = 0;
	flag = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (flag == 0)
		{
			split = ft_strsplit(line, ' ');
			while(split[cnt])
				cnt++;
			flag = 1;
		}
		i++;
		free(line);
	}
	free(line);
	size.row = i;
	size.col = cnt;
	return (size);
}

int     allocate_map(t_row_col   size, int ***temp_map)
{
	int     y;
	
//	printf("row %d col %d", size.row, size.col);
	y = 0;
	(*temp_map) = (int**)malloc(sizeof(int*) * (size.row + 1));
	while (y < size.row)
	{
		(*temp_map)[y] = (int*)malloc(sizeof(int) * (size.col + 1));
		y++;
	}
	return (1);
}

int		populate_map(int fd, int ***map, t_row_col   size)
{
	int			i;
	int			j;
	char		**split;
	char		*line;

	i = 0;
	//printf("%d, %d \n", size.row, size.col);
	while ((get_next_line(fd, &line)) > 0 && i < size.row)
	{
		split = ft_strsplit(line, ' ');
		j = 0;
		while (j < size.col)
		{
			(*map)[i][j] = ft_atoi(split[j]);
			j++;
		}
	//		printf("\n");
		i++;
		free(line);
	}
//	free(line);
	return (1);
}
