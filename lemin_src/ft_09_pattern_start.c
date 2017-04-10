/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_09_pattern_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 23:05:58 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 23:06:00 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

int				ft_is_start_pattern(t_lem *lem)
{
	char		*str;
	size_t		len;

	str = lem->map_string;
	len = ft_strlen(str);
	if (len < 7)
		return (FALSE);
	if (*str == '#' && *(str + 1) == '#')
	{
		str = str + 2;
		if (ft_strcmp(str, "start") == EQUAL)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

static void		ft_set_start_error(t_lem *lem)
{
	lem->s_err = TRUE;
}

static void		ft_start_uniq_error(t_lem *lem, char *errmess)
{
	lem->namei = START;
	lem->s_err = TRUE;
	lem->s_true = TRUE;
	ft_set_errmess(lem, errmess);
}

void			ft_check_start(t_lem *lem)
{
	if (lem->namei != NEUTRAL)
		return (ft_set_start_error(lem));
	if (ft_is_start_pattern(lem) == FALSE)
		return (ft_set_start_error(lem));
	if (lem->s_true == TRUE)
		return (ft_start_uniq_error(lem, "##start already exist"));
	if (lem->s_true == FALSE && lem->a_true == FALSE)
		return (ft_start_uniq_error(lem, "missed ANTS before ##start"));
	if (lem->end == WAITING)
		return (ft_start_uniq_error(lem, "##start after ##end"));
	lem->start = WAITING;
	ft_set_pattern_name(lem, START, "##start");
}
