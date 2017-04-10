/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16_create_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:11:47 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/04 15:11:49 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void			ft_print_rooms(t_room *rooms)
{
	t_room			*r;

	r = rooms->holder;
	ft_printf("\nrooms:\n");
	while (r)
	{
		ft_printf("%d. ", r->room_num);
		ft_printf("\"%s\" ", r->room_name);
		if (r->marker == START)
			ft_printf("%s ", "start");
		else if (r->marker == END)
			ft_printf("%s ", "end  ");
		else
			ft_printf("      ");
		ft_printf("ants: %d", r->ants);
		ft_printf(" [%d.%d]", r->x, r->y);
		ft_printf(" links: %d\n", r->links);
		r = r->next;
	}
}

t_room				*ft_get_rooms(t_line *lines, int flag)
{
	t_room			*rooms;

	if (!lines)
		return (NULL);
	rooms = NULL;
	rooms = ft_create_rooms(lines, rooms);
	rooms = ft_create_boxes(lines, rooms);
	if (flag == VALIDATOR)
		ft_print_rooms(rooms);
	if (flag == PATHES)
		ft_print_links(rooms);
	return (rooms);
}
