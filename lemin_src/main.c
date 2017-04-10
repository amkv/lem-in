/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:39:40 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/07 10:39:41 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void		ft_free_all_part_2(t_room *rooms, t_room *victim)
{
	t_room		*rm;
	int			index;

	rm = rooms->holder;
	while (rm)
	{
		index = 0;
		victim = rm;
		free(rm->room_name);
		rm->room_name = NULL;
		if (rm->links > 0)
		{
			while (index < rm->links)
			{
				free(rm->box[index]);
				rm->box[index] = NULL;
				index++;
			}
			free(rm->box);
			rm->box = NULL;
		}
		rm = rm->next;
		free(victim);
		victim = NULL;
	}
}

void			ft_exit_error(t_room *rooms, t_room *path, int flag)
{
	if (!path && (flag == VALIDATOR || flag == PATHES || flag == SHORTPATH))
		ft_printf(RED"\nno path\n"CLN);
	if (rooms)
		ft_free_all_part_2(rooms, NULL);
	ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	t_lem		*lem;
	t_line		*lines;
	t_room		*rooms;
	t_room		*path;
	int			flag;

	lem = NULL;
	if (argc > 2)
		ft_error(lem);
	set_lem(argc, argv[1], &lem);
	ft_read_and_validate(lem);
	lines = ft_final_validation(lem);
	flag = lem->flag;
	rooms = ft_get_rooms(lines, flag);
	ft_free_all_part_1(lem);
	path = ft_find_straight_short_path(rooms, flag);
	ft_print_short_path(path, flag, -1);
	ft_print_straight_trip_of_ants(path);
	ft_free_all_part_2(rooms, NULL);
	exit(EXIT_SUCCESS);
}
