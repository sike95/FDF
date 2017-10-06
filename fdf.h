/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:08:40 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/06 11:16:13 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "fdf.h"

typedef struct	s_row_col
{
	int			row;
	int			col;

}				t_row_col;

void     populate_map(int fd, char *line, int ***map);
int     allocate_map(int fd, char *line, int ***map);
t_row_col      get_size(int fd, char *line);
#endif
