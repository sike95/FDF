/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:54:47 by mmpofu            #+#    #+#             */
/*   Updated: 2017/09/27 18:21:36 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <>

t_row_col	get_map_size()
{
	int			fd;
	char		*line;
	t_row_col	rc;

	fd = open("test_maps/pyra.fdf", O_RDONLY);
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
	i--;
	rc.row = cnt;
	rc.col = i;
	return (rc);
}

