/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/05 18:28:26 by mmpofu           ###   ########.fr       */
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

	populate_map(fd, line);
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 400, 400, "mlx 420");

	//mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	//mlx_key_hook(win, my_key_funct, 0);
	//mlx_loop(mlx);	
	return (0);
}
