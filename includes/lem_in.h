/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:05:08 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/03 14:41:36 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct	s_rm
{
	char		*name;
	int			x;
	int			y;
	int			size;
}				t_rm;

typedef struct	s_lem_in
{
	char		**data;
	int			ants;
	t_rm		*rm;
	char		**links;
	int			**map;
	int			rooms;
	int			link;
	int			start;
	int			end;
	char		*lst;
	int			len;
	int			*rmf;
	int			viz;
}				t_lem_in;

t_lem_in		*init_struct(void);
void			ft_print_links(t_lem_in *lem);
void			ft_convert_links(t_lem_in *lem);
void			ft_check_match(t_lem_in *lem, char **str, int i, int j);

int				ft_read(t_lem_in *lem);
int				ft_store(t_lem_in *lem);
void			ft_swap_rooms(t_lem_in *lem);
void			ft_save_room(t_lem_in *lem, char *str);
void			ft_save_ants(t_lem_in *lem, char *str);

int				ft_is_in_list(char *node, char *list);
int				ft_count_list_len(t_lem_in *lem);
char			*add_room(t_lem_in *lem, char *lst, int rm);
int				push_count(char *lst);
void			push(t_lem_in *lem);
int				push_down (t_lem_in *lem, char *lst, int y, int x);
int				push_up (t_lem_in *lem, char *lst, int y, int x);
int				push_left (t_lem_in *lem, char *lst, int y, int x);
int				push_right (t_lem_in *lem, char *lst, int y, int x);
void			sort_rooms(t_lem_in *lem);
void			move_ants(t_lem_in *lem, int viz);
void			print_ants(t_lem_in *lem, int ant, int rm, int viz);
int				move_rec(t_lem_in *lem, int ant, int rm, int count);

int				is_error(t_lem_in *lem);
void			viz(t_lem_in *lem);

#endif
