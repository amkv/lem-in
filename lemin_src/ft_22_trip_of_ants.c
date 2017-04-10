/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21_trip_of_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:12:49 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/07 11:12:50 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void			ft_move_ant(t_room *rm, long int last, int *exit)
{
	rm->aname = rm->short_revers->aname;
	if (rm->marker == END)
		rm->ants++;
	else
	{
		rm->ants = 1;
		rm->short_revers->ants -= 1;
	}
	if (rm->aname == last && rm->marker == END)
	{
		*exit = TRUE;
		ft_printf("L%d-%s\n", rm->aname, rm->room_name);
	}
	else
		ft_printf("L%d-%s ", rm->aname, rm->room_name);
}

void				ft_print_straight_trip_of_ants(t_room *path)
{
	long int		last;
	t_room			*rm;
	int				exit;

	if (!path)
		return ;
	last = path->ants;
	path->aname = 1;
	ft_printf("\n", exit = FALSE);
	while (path->short_last_holder->ants < last + 1 && exit == FALSE)
	{
		rm = path->short_last_holder;
		while (rm && exit == FALSE)
		{
			(path->short_last_holder->ants == last) ? exit = TRUE : exit;
			if (rm->short_revers && rm->short_revers->ants > 0)
				ft_move_ant(rm, last, &exit);
			else if (rm->marker == START)
			{
				(rm->ants == 0) ? rm->aname = 0 : rm->aname++;
				ft_printf("\n");
			}
			rm = rm->short_revers;
		}
	}
}
