/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 15:23:45 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/10 09:37:49 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		anew_map(t_main_var *var)
{
	var->y = 0;
	(var->new_map) = (t_map**)malloc(sizeof(t_map*) * (var->size.row + 1));
	while (var->y < var->size.row)
	{
		(var->new_map)[var->y] = (t_map*)malloc(sizeof(t_map) * (var->size.col + 1));
		var->y++;
	}
	return (1);
}

int		make_iso(t_main_var *var)
{
	var->y = 0;
	while (var->y < var->size.row )
	{
		var->x = 0;
		while (var->x < var->size.col)
		{
			var->i = var->x * var->sz + y_shift;
			var->j = var->y * var->sz + x_shift;
			var->c = var->i - var->j;
			var->j = (var->i + var->j) / 2;
			var->point.x = var->c;
			if (var->map[var->y][var->x] > 0)
				var->j = var->j - var->map[var->y][var->x] * 10;
			var->point.y = var->j;
			var->new_map[var->y][var->x] = var->point;
			reduce_size(&var->sz, var->map, var->size);
			var->x++;
		}
		var->y++;
	}
	return (1);
}
