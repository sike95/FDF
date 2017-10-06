/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 09:30:02 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/06 11:20:17 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_row_col		get_size(int fd, char *line)
{
	t_row_col  size;
	int		flag;
	int		i;
	int		cnt;
	char	**split;

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
	}
	i--;
	size.col = i;
	size.row = cnt;
	return (size);
}

int     allocate_map(int fd, char *line, int ***map)
{
	int     y;
	int		**temp_map;
	t_row_col  size;
	
	temp_map = *map;
	size = get_size(fd, line);
	printf("row %d col %d", size.row, size.col);
	y = 0;
	(temp_map) = (int**)malloc(sizeof(int*) * (size.col + 1));
	while (y < size.col)
	{
		(temp_map)[y] = (int*)malloc(sizeof(int) * (size.row + 1));
		y++;
	}
	*map = temp_map;
	return (0);
}
/*
void	populate_map(int fd, char *line, int ***map)
{
	t_row_col	size;
	int			i;
	int			j;
	char		**split;
	int     	**temp_map;

	i = 0;
	temp_map = *map;
	fd = open("42.fdf", O_RDONLY);
	size = get_size(fd, line);
	 printf("%d", size.row);
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%d", size.row);
		split = ft_strsplit(line, ' ');
		j = 0;
		while (j < size.row)
		{
		//	temp_map[i][j] = ft_atoi(split[j]);
			printf("%d",ft_atoi(split[j]));
			j++;
		}
		printf("\n");
		i++;
	}
	*map = temp_map;
*	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			printf("%d", *(map[0][0]));
		j++;
		}
		i++;
	}
*/
//}
