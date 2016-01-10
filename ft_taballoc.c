/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taballoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:09:07 by afillion          #+#    #+#             */
/*   Updated: 2015/12/17 17:00:11 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_taballoc(int n)
{
	char	**new;
	int		i;

	i = 0;
	if (!(new = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	while (i < n)
	{
		new[i] = (char*)malloc((n + 1) * sizeof(char));
		ft_memset(new[i], '.', n);
		new[i][n] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
