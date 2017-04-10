/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_07_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:25:23 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/23 16:25:24 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void			ft_initialize_line(t_lem *lem, t_line *line)
{
	line->type = lem->namei;
	if (line->type == COMMENT)
		line->str = ft_strdup(lem->map_string);
	else if (line->type == ANTS)
		line->value = lem->ants;
	else if (line->type == START)
		return ;
	else if (line->type == END)
		return ;
	else if (line->type == ROOM)
	{
		line->str = ft_strdup(lem->room_name);
		line->x = lem->x_room;
		line->y = lem->y_room;
	}
	else if (line->type == LINKS)
	{
		line->room1 = ft_strdup(lem->room1);
		line->room2 = ft_strdup(lem->room2);
	}
	else if (line->type == BADCOM)
		line->str = ft_strdup(lem->map_string);
}

static t_line		*ft_new_line(void)
{
	t_line			*line;

	line = (t_line*)malloc(sizeof(t_line) * 1);
	if (!line)
		return (NULL);
	line->type = FALSE;
	line->str = NULL;
	line->value = FALSE;
	line->x = FALSE;
	line->y = FALSE;
	line->room1 = NULL;
	line->room2 = NULL;
	line->holder = NULL;
	line->next = NULL;
	return (line);
}

void				ft_add_line(t_lem *lem)
{
	t_line			*new;

	if (!(new = ft_new_line()))
		ft_error(lem);
	ft_initialize_line(lem, new);
	if (!lem->line)
	{
		lem->line = new;
		lem->line->holder = new;
	}
	else
	{
		new->holder = lem->line->holder;
		lem->line->next = new;
		lem->line = new;
	}
}

void				ft_free_lines(t_lem *lem)
{
	t_line			*ln;
	t_line			*victim;

	if (!lem->line)
		return ;
	if (!(ln = lem->line->holder))
		return ;
	while (ln)
	{
		victim = ln;
		if (ln->str)
			ft_free_and_null(&ln->str);
		if (ln->room1)
			ft_free_and_null(&ln->room1);
		if (ln->room2)
			ft_free_and_null(&ln->room2);
		ln = ln->next;
		free(victim);
		victim = NULL;
	}
}
