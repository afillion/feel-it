/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:34:11 by qdegraev          #+#    #+#             */
/*   Updated: 2016/01/10 10:07:30 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*list_new(void const *content, size_t content_size, char letter)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->letter = 0;
		new->tab = NULL;
	}
	else
	{
		if (!(new->content = malloc(content_size + 1)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->letter = letter;
		new->tab = NULL;
	}
	new->next = NULL;
	return (new);
}

void	list_addback(t_list **begin_list, void const *content,
		size_t content_size, char letter)
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = list_new(content, content_size, letter)))
		return ;
	if (!(*begin_list))
		*begin_list = new;
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	del_lstcontent(char **tab, char *s, int size, char letter)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		while (j <= i)
		{
			free(tab[j]);
			j++;
		}
		free(tab);
	}
	free(s);
	tab = NULL;
	s = NULL;
	size = '\0';
	letter = '\0';
}

void	list_erase(t_list **lst)
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del_lstcontent((*lst)->tab, (*lst)->content, (*lst)->content_size,
				(*lst)->letter);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	insert_pieces(t_list *lst)
{
	int		i;
	int		j;
	char	**split;

	j = 0;
	i = 0;
	if (!(split = ft_strsplit(cut_empty_lin(lst->content), '\n')))
		return ;
	while (split[i])
		i++;
	if (!(lst->tab = (char**)malloc(sizeof(char*) * i + 1)))
		return ;
	while (split[j])
	{
		if (!(lst->tab[j] = (ft_strnew(ft_strlen(split[j])))))
			return ;
		ft_memcpy(lst->tab[j], split[j], ft_strlen(split[j]));
		hash_vs_letter(lst->tab[j], '#', lst->letter);
		free(split[j]);
		j++;
	}
	free(split);
	lst->tab[j] = NULL;
}
