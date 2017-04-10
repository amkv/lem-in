/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_13_pattern_bad_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:55:11 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/28 19:55:13 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static int		ft_is_bad_command_pattern(t_lem *lem)
{
	char		*copy;

	copy = lem->map_string;
	if (ft_strlen(copy) < 5)
		return (TRUE);
	if (*copy == '#' && *(copy + 1) == '#')
	{
		copy = (copy + 2);
		if (ft_strcmp(copy, "end") == EQUAL)
			return (FALSE);
		else if (ft_strcmp(copy, "end") == EQUAL)
			return (FALSE);
		else
			return (TRUE);
	}
	else
		return (FALSE);
}

static void		ft_set_bad_command_error(t_lem *lem)
{
	lem->b_err = TRUE;
}

void			ft_check_bad_command(t_lem *lem)
{
	if (lem->namei != NEUTRAL)
		return (ft_set_bad_command_error(lem));
	if (ft_is_bad_command_pattern(lem) == FALSE)
		return (ft_set_bad_command_error(lem));
	ft_set_pattern_name(lem, BADCOM, "not a command");
}
