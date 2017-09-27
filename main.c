/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/09/26 17:25:02 by mmpofu           ###   ########.fr       */
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
	//void	*mlx;
	//void	*win;
	int		fd;
	char	*line;
	char	*map;

	t_list	*list;
	t_list	*temp;

	fd = open("42.fdf", O_RDONLY);
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 400, 400, "mlx 420");

	x = 0;
	y = 0;
	list = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		temp = malloc(sizeof(t_list));
		temp->data = line;
		temp->next = list;
		ft_putendl(list->data);
	}
	//mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	//mlx_key_hook(win, my_key_funct, 0);
	//mlx_loop(mlx);	
	while (list)
	{
		ft_putendl(list->data);
		list = list->next;
	}
	return (0);
}
