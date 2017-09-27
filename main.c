/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/09/27 18:21:31 by mmpofu           ###   ########.fr       */
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
	int		cnt;
	int		fd;
	char	*line;
	char	**map;

	t_list	*list;
	t_list	*temp;

	fd = open("test_maps/pyra.fdf", O_RDONLY);
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 400, 400, "mlx 420");

	c = 0;
	i = 0;
	x = 0;
	y = 0;
	list = NULL;
	int flag = 0;
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
/*	while ((get_next_line(fd, &line)) > 0)
	{
		while (y < i)
		{
			map[i] = (char*)malloc(sizeof(char) * (c + 1));
			i++;
		}
	}*/
	//mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	//mlx_key_hook(win, my_key_funct, 0);
	//mlx_loop(mlx);	
	return (0);
}
