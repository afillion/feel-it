/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:01:39 by afillion          #+#    #+#             */
/*   Updated: 2016/01/10 10:21:24 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	erase_piece(char **map, char **tab, int x, int y)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isalpha(tab[i][j]))
				map[x + i][y + j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}

void	free_map(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (j <= i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}
