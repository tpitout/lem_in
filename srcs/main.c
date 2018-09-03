/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:51:44 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/03 14:41:40 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_lem_in(t_lem_in *lem)
{
	ft_read(lem);
	ft_store(lem);
	if (is_error(lem))
		exit(0);
	ft_convert_links(lem);
	push(lem);
	if (!lem->lst)
	{
		ft_putstr(BOLDRED "Error : No solution\n");
		exit(0);
	}
	sort_rooms(lem);
	if (lem->viz)
	{
		viz(lem);
		move_ants(lem, lem->viz);
	}
	else
	{
		ft_print_links(lem);
		write(1, "\n", 1);
		move_ants(lem, lem->viz);
	}
}

void			ft_free(t_lem_in *lem)
{
	int			i;

	i = 0;
	free(lem->data);
	i = 0;
	free(lem->rm);
	i = 0;
	while (lem->links[i])
	{
		free(lem->links[i]);
		lem->links[i] = NULL;
		i++;
	}
	free(lem->links);
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
	free(lem->map);
	free(lem->lst);
	free(lem->rmf);
}

int				main(void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
	ft_free(lem);
	if (lem->viz)
	{
		ft_putstr(BOLDGREEN "\n\n==============================\n");
		ft_putstr(BOLDGREEN "           DONE!           \n");
		ft_putstr(BOLDGREEN "==============================\n");
	}
	free(lem);
	return (0);
}
