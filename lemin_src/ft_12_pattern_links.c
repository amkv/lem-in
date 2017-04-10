/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_12_pattern_links.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 23:19:50 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 23:19:52 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

int				ft_is_link_pattern(t_lem *lem)
{
	char		*str;
	size_t		dashes;
	size_t		len;

	str = lem->map_string;
	dashes = ft_strchr_qt(str, '-');
	len = ft_strlen(str);
	if (dashes == 0)
		return (FALSE);
	if (len < 3)
		return (FALSE);
	return (TRUE);
}

static void		ft_link_uniq_error(t_lem *lem, char *errmess)
{
	lem->namei = LINKS;
	lem->l_err = TRUE;
	lem->l_true = TRUE;
	ft_set_errmess(lem, errmess);
}

static void		ft_set_link_error(t_lem *lem)
{
	lem->l_err = TRUE;
}

static char		*ft_get_room_room_names(t_lem *lem)
{
	char		**rooms;
	char		*temp;
	char		*result;

	rooms = ft_split_by_last_char(lem->map_string, '-');
	if (!rooms)
		return (NULL);
	temp = ft_strjoin("link \"", rooms[0]);
	result = ft_strjoin(temp, "\" --> \"");
	ft_free_and_null(&temp);
	temp = ft_strjoin(result, rooms[1]);
	ft_free_and_null(&result);
	result = ft_strjoin(temp, "\"");
	ft_free_and_null(&temp);
	lem->room1 = ft_strdup(rooms[0]);
	lem->room1_ml = TRUE;
	lem->room2 = ft_strdup(rooms[1]);
	lem->room2_ml = TRUE;
	ft_free_and_null(&rooms[0]);
	ft_free_and_null(&rooms[1]);
	free(rooms);
	rooms = NULL;
	return (result);
}

void			ft_check_links(t_lem *lem)
{
	char		*room_room;

	if (lem->namei != NEUTRAL)
		return (ft_set_link_error(lem));
	if (ft_is_link_pattern(lem) == FALSE)
		return (ft_set_link_error(lem));
	if (lem->r_true == FALSE)
		return (ft_link_uniq_error(lem, "no rooms"));
	if (lem->start == WAITING)
		return (ft_link_uniq_error(lem, "missed start point room"));
	else if (lem->end == WAITING)
		return (ft_link_uniq_error(lem, "missed end point room"));
	if (lem->start == FALSE)
		return (ft_link_uniq_error(lem, "##start missed"));
	if (lem->end == FALSE)
		return (ft_link_uniq_error(lem, "##end missed"));
	if (!(room_room = ft_get_room_room_names(lem)))
		ft_link_uniq_error(lem, "bad room");
	if (ft_is_room_name_exist(lem, 1) == FALSE)
		return (ft_link_uniq_error(lem, "first room does not exist"));
	if (ft_is_room_name_exist(lem, 2) == FALSE)
		return (ft_link_uniq_error(lem, "second room does not exist"));
	lem->links++;
	ft_set_pattern_name(lem, LINKS, room_room);
	free(room_room);
}
