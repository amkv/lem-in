/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_19_print_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:34:41 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/05 19:34:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void			ft_print_name(t_room *rm, int *f, int last)
{
	if (rm->marker == END)
	{
		if (last == TRUE)
			ft_printf(BLU"[%s]"CLN""GRN"*"CLN, rm->room_name);
		else
			ft_printf(GRN"[%s]*"CLN, rm->room_name);
		return ;
	}
	else if (rm->marker == START)
	{
		if (last == TRUE)
			ft_printf(BLU"[%s]"CLN""GRN">"CLN, rm->room_name);
		else
			ft_printf(GRN"[%s]>"CLN, rm->room_name);
		return ;
	}
	if (*f == TRUE)
	{
		if (last == TRUE)
			ft_printf(BLU"[%s]"CLN, rm->room_name);
		else
			ft_printf("[%s]", rm->room_name);
	}
	else
		ft_printf("[%s]", rm->room_name);
}

static void			ft_print_one(t_room *rm, int cnt, int *f)
{
	*f = TRUE;
	ft_print_name(rm, *&f, TRUE);
	if (rm->visited == TRUE)
		ft_printf(RED" ..."CLN"\n |\n");
	else
		ft_printf(GRY" %d"CLN" \n |\n", cnt);
}

static void			ft_print_many(t_room *rm, int cnt, int *f)
{
	if (*f == TRUE && cnt != 1)
		ft_printf(" |        ");
	ft_print_name(rm, *&f, FALSE);
	ft_printf(GRY" %d"CLN" -- ", cnt);
}

static void			ft_print_in_deep(t_room *rm, int index, int counter, int *f)
{
	if (rm->visited == TRUE || rm->links == 0)
		return (ft_print_one(rm, counter, *&f));
	while (index < rm->links)
	{
		ft_print_many(rm, counter, *&f);
		rm->visited = TRUE;
		*f = FALSE;
		ft_print_in_deep(rm->box[index]->room, 0, counter + 1, *&f);
		rm->visited = FALSE;
		index++;
	}
}

void				ft_print_links(t_room *rooms)
{
	t_room			*rm;
	int				flag;

	rm = rooms->holder;
	ft_printf("\ndesignations:\n");
	ft_printf("----------------------------------\n");
	ft_printf(GRN"[ ]>"CLN" start room\n");
	ft_printf(GRN"[ ]*"CLN" end room\n");
	ft_printf("[ ]  simple room\n");
	ft_printf(BLU"[ ]"CLN"  dead end room\n");
	ft_printf(RED"..."CLN"  infiniti loop\n");
	ft_printf("----------------------------------\n");
	ft_printf("\n");
	while (rm)
	{
		flag = FALSE;
		ft_print_in_deep(rm, 0, 1, &flag);
		rm = rm->next;
	}
	ft_printf("\n");
}
