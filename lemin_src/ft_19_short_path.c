/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_20_find_short_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:16:01 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/06 14:16:02 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static t_room	*ft_add_path(t_room *path, t_room *rm)
{
	t_room		*revers;

	if (!path)
	{
		path = rm;
		path->path_holder = rm;
		path->path = NULL;
		path->revers = NULL;
	}
	else
	{
		path->path = rm;
		revers = path;
		rm->path_holder = path->path_holder;
		path = rm;
		rm->path = NULL;
		rm->revers = revers;
	}
	return (path);
}

static t_room	*ft_copy_full_path(t_room *room, t_room *rm)
{
	t_room		*short_path;
	t_room		*short_path_copy;
	t_room		*previous_room;
	int			index;

	rm = room;
	short_path = rm;
	short_path_copy = short_path;
	short_path->short_holder = short_path;
	previous_room = rm;
	index = 0;
	while (rm)
	{
		short_path->short_next = rm->path;
		if (index == 0)
			short_path->short_revers = NULL;
		else
			short_path->short_revers = previous_room;
		short_path = short_path->short_next;
		previous_room = rm;
		rm = rm->path;
		index++;
	}
	short_path_copy->short_last_holder = previous_room;
	return (short_path_copy);
}

static t_room	*ft_no_next_links(t_room *path, t_room *rm, int *o)
{
	int			is_end;
	t_room		*copy;

	path = ft_add_path(path, rm);
	ft_print_path(path, o);
	if (rm->path_holder->marker != START)
		return (path);
	is_end = FALSE;
	copy = path->path_holder;
	while (copy)
	{
		(copy->marker == END) ? (is_end = TRUE) : (is_end);
		copy = copy->path;
	}
	if (is_end == TRUE && rm->step_num <= o[MIN_STEPS])
	{
		rm->holder->short_path = ft_copy_full_path(rm->path_holder, NULL);
		o[MIN_STEPS] = rm->step_num;
	}
	o[END_ROOM] = TRUE;
	return (path);
}

static t_room	*ft_return_path(t_room *rm, t_room *path, int *o, int index)
{
	rm->step_num = ++o[COUNTER];
	if (rm->visited == TRUE)
	{
		o[INFINITILOOP] = TRUE;
		return (path);
	}
	if (rm->links == NOLINKS)
		return (ft_no_next_links(path, rm, o));
	while (index < rm->links)
	{
		path = ft_add_path(path, rm);
		rm->visited = TRUE;
		path = ft_return_path(rm->box[index]->room, path, o, 0);
		o[COUNTER]--;
		if (o[INFINITILOOP] == TRUE)
			path = ft_no_next_links(path, rm, o);
		rm->visited = FALSE;
		index++;
	}
	return (path);
}

t_room			*ft_find_straight_short_path(t_room *rooms, int flag)
{
	t_room		*path;
	t_room		*copy;
	t_room		*rm;
	int			*o;

	o = (int*)malloc(sizeof(int) * 5);
	o[FLAG] = flag;
	o[MIN_STEPS] = rooms->room_num;
	path = NULL;
	rm = rooms->holder;
	while (rm)
	{
		o[END_ROOM] = FALSE;
		o[COUNTER] = 0;
		o[INFINITILOOP] = FALSE;
		copy = rm;
		ft_return_path(copy, NULL, o, 0);
		if (rm->holder->short_path)
			path = rm->holder->short_path;
		rm = rm->next;
	}
	free(o);
	if (!path)
		ft_exit_error(rooms, path, flag);
	return (path);
}
