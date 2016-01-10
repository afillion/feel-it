/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:53:28 by qdegraev          #+#    #+#             */
/*   Updated: 2016/01/10 10:29:02 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_errorbox(int i, t_list *lst)
{
	ft_putendl("error");
	if (i == 1)
		list_erase(&lst);
	exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;
	char	**map;
	int		i;
	int		n;

	lst = NULL;
	if (argc != 2)
		return (ft_errorbox(0, lst));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_errorbox(0, lst);
	lst = ft_recordfile(fd);
	n = ft_small_square(ft_lstlen(lst));
	map = map_expand(lst, &n);
	list_erase(&lst);
	i = 0;
	while (i < n)
	{
		ft_putendl(map[i]);
		i++;
	}
	free_map(map);
	return (0);
}
