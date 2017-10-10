/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:24:28 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/10 09:37:33 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void			init_reduce_size(t_rs *var)
{
	var->j = 0;
	var->i = 0;
	var->x = 0;
	var->y = 0;
}

int				reduce_size(int *sz, int **map, t_row_col size)
{
	t_rs	var;

	init_reduce_size(&var);
	while (var.y < size.row)
	{
		var.x = 0;
		while (var.x < size.col)
		{
			var.i = var.x * (*sz) + 300;
			var.j = var.y * (*sz) + 100;
			var.c = var.i - var.j;
			var.j = (var.i + var.j) / 2;
			if (map[var.y][var.x] > 0)
				var.j = var.j - map[var.y][var.x] * 10;
			var.x++;
		}
		var.y++;
	}
	if (var.i > 800 || var.j > 800)
	{
		*sz = *sz - 1;
		reduce_size(sz, map, size);
	}
	return (*sz);
}

int				main(int argc, char **argv)
{
	t_main_var	var;

	var.x = 0;
	var.sz = 20;
	var.y = 0;
	if (argc == 2)
	{
		var.file = argv[1];
		var.fd = open(var.file, O_RDONLY);
		var.size = get_size(var.fd);
		allocate_map(var.size, &var.map);
		close(var.fd);
		var.fd = open(var.file, O_RDONLY);
		var.mlx = mlx_init();
		var.win = mlx_new_window(var.mlx, 900, 900, "mlx 420");
		populate_map(var.fd, &var.map, var.size);
	}
	else
	{
		ft_putstr("Invalid File");
		return (0);
	}
	var.sz = reduce_size(&var.sz, var.map, var.size);
	anew_map(&var);
	make_iso(&var);
	var.y = 0;
	while (var.y < var.size.row)
	{
		var.x = 0;
		while (var.x < var.size.col)
		{
			if (var.x != var.size.col - 1)
			{
				connecter(var.mlx, var.win, var.new_map[var.y]
					[var.x], var.new_map[var.y][var.x + 1]);
			}
			if (var.y != var.size.row - 1)
			{
				connecter(var.mlx, var.win, var.new_map[var.y][var.x],
						var.new_map[var.y + 1][var.x]);
			}
			var.x++;
		}
		var.y++;
	}
	mlx_key_hook(var.win, my_key_funct, 0);
	mlx_loop(var.mlx);
	return (0);
}
