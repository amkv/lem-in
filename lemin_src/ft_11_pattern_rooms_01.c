/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_11_pattern_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 23:19:34 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 23:19:36 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void		ft_set_room_error(t_lem *lem)
{
	lem->r_err = TRUE;
}

static void		ft_free_room_pattern(char **room)
{
	if (room)
	{
		if (room[0])
			ft_free_and_null(&room[0]);
		if (room[1])
			ft_free_and_null(&room[1]);
		if (room[2])
			ft_free_and_null(&room[2]);
		free(room);
		room = NULL;
	}
}

static void		ft_room_uniq_error(t_lem *lem, char **room, char *errmess)
{
	lem->namei = ROOM;
	lem->r_err = TRUE;
	lem->r_true = TRUE;
	ft_free_room_pattern(room);
	ft_set_errmess(lem, errmess);
}

static void		ft_get_room_name_and_coordinates(t_lem *lem)
{
	char		**room;
	int			error;

	room = ft_strsplit(lem->map_string, ' ');
	lem->room_name = ft_strdup(room[0]);
	lem->room_name_ml = TRUE;
	lem->x_room = ft_atoi_werror(room[1], &error);
	if (error == 0)
		return (ft_room_uniq_error(lem, room, "room: bad x"));
	if (lem->x_room < 0)
		return (ft_room_uniq_error(lem, room, "room: negative x"));
	lem->y_room = ft_atoi_werror(room[2], &error);
	if (error == 0)
		return (ft_room_uniq_error(lem, room, "room: bad y"));
	if (lem->y_room < 0)
		return (ft_room_uniq_error(lem, room, "room: negative y"));
	ft_free_room_pattern(room);
}

void			ft_check_room(t_lem *lem)
{
	char		*val_room_name;

	if (lem->namei != NEUTRAL)
		return (ft_set_room_error(lem));
	if (ft_is_room_pattern(lem) == FALSE)
		return (ft_set_room_error(lem));
	if (lem->a_true == FALSE && lem->r_true == FALSE)
		return (ft_room_uniq_error(lem, NULL, "missed ants before room"));
	if (lem->l_true == TRUE && lem->r_true == TRUE)
		return (ft_room_uniq_error(lem, NULL, "room after link"));
	ft_get_room_name_and_coordinates(lem);
	if (lem->r_err == TRUE)
		return ;
	ft_set_start_and_end_room(lem);
	lem->rooms++;
	val_room_name = ft_set_room_validator_name(lem);
	ft_set_pattern_name(lem, ROOM, val_room_name);
	ft_free_and_null(&val_room_name);
}
