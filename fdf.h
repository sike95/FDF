/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:08:40 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/10 09:52:15 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H
# define 	y_shift  400
# define	x_shift  100

#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "fdf.h"
#include <math.h>

typedef struct	s_rs
{
	int			c;
	int			j;
	int			i;
	int			x;
	int			y;
}				t_rs;

typedef struct 		s_var
{
	int				x;
	int				y;
	int				j;
	int				i;
	int				c;
}					t_var;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_delta
{
	double			x;
	double			y;
}					t_delta;

typedef struct		s_move
{
	double			x;
	double			y;
}					t_move;

typedef struct		s_vector
{
	t_move			mv;
	t_delta			d;
}					t_vector;



typedef struct		s_map
{
	int				x;
	int				y;
}					t_map;

typedef struct		s_row_col
{
	int				row;
	int				col;

}					t_row_col;

typedef struct		s_main_var
{
	int         x;
	int         sz;
	int         y;
	int         i;
	int         j;
	int         c;
	char        *file;
	void        *mlx;
	void        *win;
	int         **map;
	int         fd;
	t_row_col   size;
	t_map       **new_map;
	t_map       point;
}				t_main_var;

typedef struct		s_get_size
{
	t_row_col   size;
	int         flag;
	int         i;
	int         cnt;
	char        **split;
	char        *line;
} 				t_get_size;

int     			reduce_size(int *sz, int **map, t_row_col size);
int    				 make_iso(t_main_var *var);
int    				 anew_map(t_main_var *var);
void				connecter(void *mlx, void *win, t_map p0, t_map p1);
int  				  populate_map(int fd, int ***map, t_row_col   size);
int  				  allocate_map(t_row_col   size, int ***map);
t_row_col 		     get_size(int fd);	
#endif
