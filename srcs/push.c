/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:38:08 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/02 15:38:10 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		push_right(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		crawl_right(lem, lst, y, x + 1);
		lst = add_room(lem, lst, x);
		crawl_up(lem, lst, y - 1, x);
		crawl_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		push_right(lem, lst, y, x + 1);
	return (0);
}

int		push_left(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		push_left(lem, lst, y, x - 1);
		lst = add_room(lem, lst, x);
		push_up(lem, lst, y - 1, x);
		push_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		push_left(lem, lst, y, x - 1);
	return (0);
}

int		push_up(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		push_up(lem, lst, y - 1, x);
		lst = add_room(lem, lst, y);
		push_left(lem, lst, y, x - 1);
		push_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		push_up(lem, lst, y - 1, x);
	return (0);
}

int		push_down(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		push_down(lem, lst, y + 1, x);
		lst = add_room(lem, lst, y);
		push_left(lem, lst, y, x - 1);
		push_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		push_down(lem, lst, y + 1, x);
	return (0);
}

void	push(t_lem_in *lem)
{
	char *tmp;

	tmp = ft_strdup(lem->rm[0].name);
	push_right(lem, tmp, 0, 0);
	free(tmp);
}
