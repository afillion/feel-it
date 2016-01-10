/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:50 by afillion          #+#    #+#             */
/*   Updated: 2015/12/16 14:36:46 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lstlen(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	*hash_vs_letter(char *s, char hash, char letter)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == hash)
			s[i] = letter;
		else
			i++;
	}
	return (s);
}
