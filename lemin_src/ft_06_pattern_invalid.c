/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_05_patterns_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:08:13 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/22 17:08:14 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

/*
** function count characters ' ', '#', '-', '0-9'
*/

static void		ft_just_a_string(t_lem *lem)
{
	char		*str;
	char		*cp;
	int			cn[4];

	cn[0] = 0;
	cn[1] = 0;
	cn[2] = 0;
	cn[3] = 0;
	str = lem->map_string;
	cp = str;
	while (*str)
	{
		(*str == '-') ? (cn[0]++) : (cn[0]);
		(ft_isalpha(*str) == TRUE) ? (cn[1]++) : (cn[1]);
		(*str == '#') ? (cn[2]++) : (cn[2]);
		(*str == ' ') ? (cn[3]++) : (cn[3]);
		str++;
	}
	if (cn[0] == 0 && cn[1] > 0 && cn[2] == 0 && cn[3] == 0)
		ft_set_errmess(lem, "just a string");
	else if (cn[0] == 0 && cn[1] > 0 && cn[2] > 0 && cn[3] == 0 && *cp != '#')
		ft_set_errmess(lem, "just a string");
}

/*
** is every character in the line printable? (ASCII)
** if not, count how many characters non-printable
*/

static void		ft_check_non_print_char(t_lem *lem)
{
	char		*copy;
	char		*str;

	copy = lem->map_string;
	str = lem->map_string;
	while (*copy)
	{
		if (ft_isprint(*copy++) == 0)
		{
			lem->non_print++;
			if (*str == '#' && (*(str + 1) && *(str + 1) != '#'))
				;
			else if (lem->non_print == 1)
				ft_set_errmess(lem, "non print char");
		}
	}
	if (lem->non_print > 0)
		lem->non_print /= 2;
}

/*
** line started from
*/

static void		ft_line_started_ended_(t_lem *lem)
{
	char		c;

	c = *lem->map_string;
	if (ft_strcmp("", lem->map_string) == 0)
		return (ft_set_errmess(lem, "empty line"));
	if (c == 'L')
		return (ft_set_errmess(lem, "started from \'L\'"));
	if (c == ' ')
		return (ft_set_errmess(lem, "started from \' \'"));
	if (lem->map_string[(int)ft_strlen(lem->map_string) - 1] == ' ' &&
		ft_is_comment_pattern(lem) == FALSE)
		return (ft_set_errmess(lem, "ended with \' \'"));
}

/*
**	check commands ##end and ##start for print uniq error
**
**
**	static void		ft_check_command(t_lem *lem)
**	{
**	size_t		len;
**	char		*str;
**
**	str = lem->map_string;
**	len = ft_strlen(str);
**	if (len > 2)
**	{
**		if (*str == '#' && *(str + 1) == '#')
**		{
**			if (ft_is_start_pattern(lem) == FALSE
**				&& ft_is_end_pattern(lem) == FALSE)
**				return (ft_set_errmess(lem, "bad command"));
**			else
**				return ;
**		}
**		else
**			return ;
**	}
**	}
*/

/*
** is room name exist?
*/

int				ft_is_room_name_exist(t_lem *lem, int num)
{
	t_line		*line;
	int			count;
	char		*room;

	line = lem->line->holder;
	count = 0;
	room = NULL;
	if (lem->r_true == FALSE || !line)
		return (FALSE);
	if (num == 1)
		room = lem->room1;
	else if (num == 2)
		room = lem->room2;
	while (line)
	{
		if (line->type == ROOM && line->str && ft_strcmp(line->str, room) == 0)
			count++;
		line = line->next;
	}
	if (count == 0)
		return (FALSE);
	else
		return (TRUE);
}

/*
** function check the line for multiple parametrs
*/

void			ft_check_invalid(t_lem *lem)
{
	ft_line_started_ended_(lem);
	if (lem->i_err == TRUE)
		return ;
	ft_check_non_print_char(lem);
	if (lem->i_err == TRUE)
		return ;
	ft_just_a_string(lem);
	if (lem->i_err == TRUE)
		return ;
	lem->i_err = FALSE;
}
