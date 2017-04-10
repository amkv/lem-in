/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_pattern_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 23:19:07 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 23:19:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

int				ft_is_end_pattern(t_lem *lem)
{
	char		*str;
	size_t		len;

	str = lem->map_string;
	len = ft_strlen(str);
	if (len < 5)
		return (FALSE);
	if (*str == '#' && *(str + 1) == '#')
	{
		str = str + 2;
		if (ft_strcmp(str, "end") == EQUAL)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

static void		ft_set_end_error(t_lem *lem)
{
	lem->e_err = TRUE;
}

static void		ft_end_uniq_error(t_lem *lem, char *errmess)
{
	lem->namei = START;
	lem->e_err = TRUE;
	lem->e_true = TRUE;
	ft_set_errmess(lem, errmess);
}

void			ft_check_end(t_lem *lem)
{
	if (lem->namei != NEUTRAL)
		return (ft_set_end_error(lem));
	if (ft_is_end_pattern(lem) == FALSE)
		return (ft_set_end_error(lem));
	if (lem->e_true == TRUE)
		return (ft_end_uniq_error(lem, "##end already exist"));
	if (lem->e_true == FALSE && lem->a_true == FALSE)
		return (ft_end_uniq_error(lem, "missed ants before ##end"));
	if (lem->start == WAITING)
		return (ft_end_uniq_error(lem, "##end after ##start"));
	lem->end = WAITING;
	ft_set_pattern_name(lem, END, "##end");
}
