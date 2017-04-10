/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_18_create_boxes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:33:23 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/04 21:33:24 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static t_box		*ft_new_box(int index, t_room *room)
{
	t_box			*new;

	new = (t_box*)malloc(sizeof(t_box) * 1);
	new->num = index + 1;
	new->room = room;
	new->room_name = room->room_name;
	return (new);
}

static void			ft_fill_boxes(t_line *lines, t_room *rooms, t_room *one)
{
	t_line			*ln;
	t_room			*rm;
	int				index;

	ln = lines->holder;
	index = 0;
	while (ln)
	{
		if (ln->type == LINKS && ft_strcmp(one->room_name, ln->room1) == EQUAL)
		{
			rm = rooms->holder;
			while (rm)
			{
				if (ft_strcmp(ln->room2, rm->room_name) == EQUAL)
				{
					one->box[index] = ft_new_box(index, rm);
					index++;
				}
				rm = rm->next;
			}
		}
		ln = ln->next;
	}
}

t_room				*ft_create_boxes(t_line *lines, t_room *rooms)
{
	t_room			*rm;
	t_line			*ln;

	rm = rooms->holder;
	while (rm)
	{
		ln = lines->holder;
		while (ln)
		{
			if (ln->type == LINKS)
			{
				if (ft_strcmp(rm->room_name, ln->room1) == EQUAL)
					rm->links++;
			}
			ln = ln->next;
		}
		rm->box = (t_box**)malloc(sizeof(t_box) * rm->links);
		ft_fill_boxes(lines, rooms, rm);
		rm = rm->next;
	}
	return (rooms);
}
