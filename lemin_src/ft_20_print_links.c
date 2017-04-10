/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_22_print_possible_pathes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 22:01:46 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/10 22:01:47 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

void			ft_print_path(t_room *rooms, int *o)
{
	t_room		*rm;
	int			index;

	if (!rooms)
		return ;
	if (rooms->path_holder->path == NULL)
		return ;
	if (o[FLAG] != PATHES)
		return ;
	rm = rooms->path_holder;
	index = 0;
	while (rm)
	{
		if (rm->marker == START)
			ft_printf(GRN"[%s]>"CLN, rm->room_name);
		else if (rm->marker == END)
			ft_printf(GRN"[%s]*"CLN, rm->room_name);
		else
			ft_printf("[%s]", rm->room_name);
		rm = rm->path;
		if (rm)
			ft_printf(" -- ");
		index++;
	}
	ft_printf("\n");
}

void			ft_print_short_path(t_room *rooms, int flag, int index)
{
	t_room		*rm;

	if (!rooms || (flag != PATHES && flag != VALIDATOR && flag != SHORTPATH))
		return ;
	ft_printf("\n");
	if (flag != SHORTPATH)
		ft_printf("shortest path:\n");
	rm = rooms->short_holder;
	while (rm)
	{
		if (rm->marker == START)
			ft_printf(GRN"[%s]>"CLN, rm->room_name);
		else if (rm->marker == END)
			ft_printf(GRN"[%s]*"CLN, rm->room_name);
		else
			ft_printf("[%s]", rm->room_name);
		rm = rm->short_next;
		if (rm)
			ft_printf(" -- ");
		index++;
	}
	ft_printf("\n");
	if (flag != SHORTPATH)
		ft_printf("%d steps for ants\n", index);
}
