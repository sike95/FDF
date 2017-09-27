/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 06:45:03 by mmpofu            #+#    #+#             */
/*   Updated: 2017/08/24 18:02:50 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(char c, char b)
{
	if (c == b)
		return (1);
	return (0);
}

static int	w_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_char(str[i], c))
			i++;
		while (str[i] && !is_char(str[i], c))
		{
			count++;
			while (str[i] && !is_char(str[i], c))
				i++;
		}
	}
	return (count);
}

static int	w_len(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && is_char(str[i], c))
		i++;
	while (str[i] && !is_char(str[i], c))
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * (w_count((char*)s, c) + 1))))
		return (NULL);
	new[0] = NULL;
	while (*s && j < w_count((char *)s, c))
	{
		k = 0;
		while (*s && is_char(s[i], c))
			i++;
		if (!(new[j] = (char*)malloc(sizeof(char) * (w_len((char*)s, c) + 1))))
			return (NULL);
		while (*s && !is_char(s[i], c))
			new[j][k++] = s[i++];
		new[j++][k] = '\0';
		new[j] = 0;
	}
	return (new);
}
