/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:09:32 by afillion          #+#    #+#             */
/*   Updated: 2016/01/10 10:25:07 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_board(char **map, char **tab, int x, int y)
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
				map[x + i][y + j] = tab[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}

char	**map_expand(t_list *lst, int *n)
{
	char **map;

	map = ft_taballoc(*n);
	if (backtrack_map2(lst, map) == 1)
		return (map);
	if (backtrack_map2(lst, map) == 0)
	{
		(*n)++;
		free_map(map);
		return (map_expand(lst, n));
	}
	return (NULL);
}

int		backtrack_map2(t_list *lst, char **map)
{
	int i;
	int j;

	if (!lst)
		return (1);
	i = 0;
	j = 0;
	while (ft_resolve(map, lst->tab, &i, &j))
	{
		ft_fill_board(map, lst->tab, i, j);
		if (backtrack_map2(lst->next, map))
		{
			return (1);
		}
		else
		{
			erase_piece(map, lst->tab, i, j);
			j++;
		}
	}
	return (0);
}

int		ft_resolve(char **map, char **tab, int *i, int *j)
{
	while (map[*i])
	{
		while (map[*i][*j])
		{
			if (check_board(map, tab, *i, *j))
			{
				return (1);
			}
			else
				(*j)++;
		}
		(*i)++;
		*j = 0;
	}
	return (0);
}

int		check_board(char **map, char **tab, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		if (!(map[x + i]) || ft_strlen(map[x + i] + y) < ft_strlen(tab[i]))
			return (0);
		while (tab[i][j])
		{
			if (map[x + i][y + j] == '.' && ft_isalpha(tab[i][j]))
				j++;
			else if (tab[i][j] == '.')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
