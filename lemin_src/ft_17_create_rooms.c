/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_17_create_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:25:20 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/04 20:25:21 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static t_room		*ft_new_room(t_line *line)
{
	t_room			*room;

	if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
		return (NULL);
	room->room_name = ft_strdup(line->str);
	room->x = line->x;
	room->y = line->y;
	room->marker = NEUTRAL;
	room->next = NULL;
	room->holder = NULL;
	room->ants = 0;
	room->box = NULL;
	room->links = 0;
	room->visited = FALSE;
	room->step_num = FALSE;
	room->path = NULL;
	room->path_holder = NULL;
	room->aname = FALSE;
	room->revers = NULL;
	room->short_path = NULL;
	room->short_next = NULL;
	room->short_holder = NULL;
	room->short_revers = NULL;
	room->short_last_holder = NULL;
	return (room);
}

static t_room		*ft_add_room(t_room *rooms, t_line *line)
{
	t_room			*new;

	new = ft_new_room(line);
	if (!rooms)
	{
		rooms = new;
		rooms->holder = new;
		new->room_num = 1;
	}
	else
	{
		new->holder = rooms->holder;
		new->room_num = rooms->room_num + 1;
		rooms->next = new;
		rooms = new;
	}
	return (rooms);
}

static void			ft_create_one_room(
		t_room **room, t_line *ln, int *start_end, int ants)
{
	*room = ft_add_room(*room, ln);
	if (*start_end != FALSE)
	{
		(*room)->marker = *start_end;
		*start_end = FALSE;
	}
	if ((*room)->marker == START)
		(*room)->ants = ants;
}

t_room				*ft_create_rooms(t_line *lines, t_room *rooms)
{
	t_line			*ln;
	int				ants;
	int				start_end;

	ln = lines->holder;
	start_end = FALSE;
	ants = 0;
	while (ln)
	{
		if (ln->type == ANTS)
			ants = ln->value;
		else if (ln->type == COMMENT || ln->type == BADCOM || ln->type == LINKS)
			;
		else if (ln->type == START || ln->type == END)
			start_end = ln->type;
		else
			ft_create_one_room(&rooms, ln, &start_end, ants);
		ln = ln->next;
	}
	return (rooms);
}
