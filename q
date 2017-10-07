/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/07 11:38:40 by mmpofu           ###   ########.fr       */
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
	t_row_col size;
	
   	x = 0;
	y = 0;
	fd = open("42.fdf", O_RDONLY);
	size = get_size(fd);
	printf("%d, %d \n", size.row, size.col);
	allocate_map(size, &map);
	close(fd);
	fd = open("42.fdf", O_RDONLY);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 420");
	populate_map(fd, &map, size);
	while (y < size.row )
	{
		x = 0;
		while (x < size.col)
		{
			printf("%d", map[y][x]);
			mlx_pixel_put(mlx, win, y + 200 , x + 200, 0x00FFFFFF);
			x++;
		}
		printf("\n");
		y++;
	}
	//mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);	
	return (0);
}
