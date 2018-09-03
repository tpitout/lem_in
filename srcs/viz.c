/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:52:53 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/03 14:43:39 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printheader(void)
{
	ft_putstr(CLEAN);
	ft_putstr(BOLDGREEN "==============================\n");
	ft_putstr(BOLDGREEN "       TREDX / LEM-IN           \n");
	ft_putstr(BOLDGREEN "==============================\n" RESET);
}

void	printcomments(t_lem_in *lem)
{
	int	i;

	i = 1;
	ft_putstr(YELLOW "\n\nCOMMENTS/COMMANDS \n" RESET);
	ft_putstr(YELLOW "==============================\n" RESET);
	while (lem->data && lem->data[i] != NULL)
	{
		if (lem->data[i][1] == '#')
		{
			ft_putstr(lem->data[i]);
			ft_putstr("\n");
		}
		i++;
	}
}

void	viz(t_lem_in *lem)
{
	char	**rooms;
	int		i;

	i = 0;
	rooms = ft_strsplit(lem->lst, '-');
	printheader();
	ft_putstr("\nANTS: " BOLDCYAN);
	ft_putnbr(lem->ants);
	printcomments(lem);
	ft_putstr(YELLOW "==============================\n" RESET);
}
