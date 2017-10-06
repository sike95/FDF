/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/06 18:50:50 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "fdf.h"

int		my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main()
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		c;
	void	*mlx;
	void	*win;
	int		**map;
	int		fd;
	char	*line;
	t_row_col size;
	i = 0;
	j = 0;
	fd = open("42.fdf", O_RDONLY);
	size = get_size(fd, line);
//	printf("%d, %d \n", size.row, size.col);
	map = allocate_map(fd, line, map, size);
	close(fd);
	fd = open("42.fdf", O_RDONLY);
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 400, 400, "mlx 420");
	map = populate_map(fd, line, map, size);

	while (i < size.row )
	{
		j = 0;
		while (j < size.col)
		{
			printf("%d", map[i][j]);
//			mlx_pixel_put(mlx, win, i, j, 0x00FFFFFF);
			j++;
		}
		printf("\n");
		i++;
	}
//	mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
//	mlx_key_hook(win, my_key_funct, 0);
//	mlx_loop(mlx);	
	return (0);
}
