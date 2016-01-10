/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:31:02 by qdegraev          #+#    #+#             */
/*   Updated: 2016/01/10 10:34:21 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*cut_empty_lin(char *s)
{
	int		i;
	char	*s2;

	s2 = "....\n\0";
	i = 0;
	while (s[i])
	{
		if (ft_strnequ(s + i, s2, 4) == 1)
			str_replace(s + i, "\n\n\n\n");
		i++;
	}
	s = src_emptycol(s);
	return (s);
}

char	*src_emptycol(char *s)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	while (i < 4)
	{
		k = 0;
		if (s[k + i] == '.' || s[k + i] == '\n')
		{
			while (k + i < 20 && (s[k + i] == '.' || s[k + i] == '\n'))
			{
				k += 5;
				j++;
			}
		}
		if (j == 4 || j == 5)
			str_replace_col(s + i, "\n\n\n\n");
		i++;
		j = 0;
	}
	return (s);
}

char	*cut_empty_col(char *s)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (src_emptycol(s + i))
		{
			ft_putendl("srcemptycol ok");
			str_replace_col(s + i, "\n\n\n\n");
		}
		i++;
	}
	return (s);
}

void	str_replace(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

void	str_replace_col(char *dest, const char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (src[i] && j < 20)
	{
		dest[j] = src[i];
		i++;
		j += 5;
	}
}
