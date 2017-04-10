/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_08_pattern_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:26:55 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 20:26:57 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static int		ft_is_ants_pattern(t_lem *lem)
{
	char		*str;
	size_t		len;

	str = lem->map_string;
	len = ft_strlen(str);
	if (len == 0)
		return (FALSE);
	if (len == 1)
	{
		if (ft_isdigit(*str) == TRUE)
			return (TRUE);
		else
			return (FALSE);
	}
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit(*str) == TRUE)
	{
		if (ft_strchr_qt(str, ' ') == 0 && ft_strchr_qt(str, '-') == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

static void		ft_set_ants_error(t_lem *lem)
{
	lem->a_err = TRUE;
}

static void		ft_ants_uniq_error(t_lem *lem, char *errmess)
{
	lem->namei = ANTS;
	lem->a_err = TRUE;
	lem->a_true = TRUE;
	ft_set_errmess(lem, errmess);
}

void			ft_check_ants(t_lem *lem)
{
	int			error;
	int			result;
	char		*str;

	str = lem->map_string;
	if (lem->namei != NEUTRAL)
		return (ft_set_ants_error(lem));
	if (ft_is_ants_pattern(lem) == FALSE)
		return (ft_set_ants_error(lem));
	if (lem->a_true == TRUE)
		return (ft_ants_uniq_error(lem, "ants: already exist"));
	result = ft_atoi_werror(str, &error);
	if (error == 0)
		return (ft_ants_uniq_error(lem, "ants: extra character(s) || > MAX"));
	if (result <= 0)
		return (ft_ants_uniq_error(lem, "ants: should be greater then 0"));
	if (lem->a_true == FALSE)
	{
		lem->ants = result;
		ft_set_pattern_name(lem, ANTS, "ants");
	}
}
