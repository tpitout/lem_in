/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:51:18 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/03 11:39:40 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_in_list(char *node, char *list)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (!ft_strcmp(node, s[i]))
		{
			j = 0;
			while (*(s + i + j))
				free(s[i + j++]);
			free(s);
			return (1);
		}
		free(s[i++]);
	}
	free(s);
	return (0);
}

int		ft_count_list_len(t_lem_in *lem)
{
	char	**str;
	int		len;

	str = ft_strsplit(lem->lst, '-');
	len = 0;
	while (*(str + len))
		free(str[len++]);
	free(str);
	return (len);
}

char	*add_room(t_lem_in *lem, char *lst, int rm)
{
	char *s;

	if (!ft_is_in_list(lem->rm[rm].name, lst))
	{
		s = ft_strjoin(lst, "-");
		lst = ft_strjoin(s, lem->rm[rm].name);
		free(s);
		if (rm == lem->rooms - 1)
		{
			if (push_count(lst) < lem->len)
			{
				lem->len = push_count(lst);
				free(lem->lst);
				lem->lst = ft_strdup(lst);
			}
		}
	}
	return (lst);
}

int		push_count(char *lst)
{
	char	**str;
	int		len;

	str = ft_strsplit(lst, '-');
	len = 0;
	while (*(str + len))
	{
		free(str[len]);
		len++;
	}
	free(str);
	return (len);
}
