/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/06 11:15:29 by mmpofu           ###   ########.fr       */
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
	int		c;
	//void	*mlx;
	//void	*win;
	int		**map;
	int		fd;
	char	*line;
	t_row_col *size;

	size = NULL;
	fd = open("42.fdf", O_RDONLY);
	allocate_map(fd, line, &(map));
	printf("\n");
//	populate_map(fd, line, &map);
/*	i = 0;
	while (i < 11)
	{
		x = 0;
		while (x < 19)
		{
			printf("%d", map[i][x]);
			x++;		
		}
		printf("\n");
		i++;
	}*/
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 400, 400, "mlx 420");

	//mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	//mlx_key_hook(win, my_key_funct, 0);
	//mlx_loop(mlx);	
	return (0);
}
