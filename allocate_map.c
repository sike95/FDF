/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 09:30:02 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/08 18:03:08 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_row_col		get_size(int fd)
{
	t_get_size	var;

	var.i = 0;
	var.cnt = 0;
	var.flag = 0;
	while ((get_next_line(fd, &var.line)) > 0)
	{
		if (var.flag == 0)
		{
			var.split = ft_strsplit(var.line, ' ');
			while (var.split[var.cnt])
				var.cnt++;
			var.flag = 1;
		}
		var.i++;
	}
	free(var.line);
	var.size.row = var.i;
	var.size.col = var.cnt;
	return (var.size);
}

int				allocate_map(t_row_col size, int ***temp_map)
{
	int			y;

	y = 0;
	(*temp_map) = (int**)malloc(sizeof(int*) * (size.row + 1));
	while (y < size.row)
	{
		(*temp_map)[y] = (int*)malloc(sizeof(int) * (size.col + 1));
		y++;
	}
	return (1);
}

int				populate_map(int fd, int ***map, t_row_col size)
{
	int			i;
	int			j;
	char		**split;
	char		*line;

	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		j = 0;
		while (j < size.col)
		{
			(*map)[i][j] = ft_atoi(split[j]);
			j++;
		}
		i++;
		free(line);
	}
	return (1);
}

void			connecter(void *mlx, void *win, t_map p0, t_map p1)
{
	t_vector	vec;
	t_move		step;
	double		crawl;
	int			i;

	if ((vec.d.x = (p1.x - p0.x))
			> (vec.d.y = (p1.y - p0.y)))
		crawl = fabs(vec.d.x);
	else
		crawl = fabs(vec.d.y);
	vec.mv.x = vec.d.x / crawl;
	vec.mv.y = vec.d.y / crawl;
	step.x = p0.x;
	step.y = p0.y;
	i = 0;
	while (i < crawl)
	{
		step.x = step.x + vec.mv.x;
		step.y = step.y + vec.mv.y;
		mlx_pixel_put(mlx, win, (int)step.x, (int)step.y, 0x00FFFF00);
		i++;
	}
}
