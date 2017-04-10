/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:49:49 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/09 11:49:52 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void		ft_print_string_and_free(t_lem *lem)
{
	if (lem->flag == NOCOMMENT)
	{
		if (lem->namei != COMMENT && lem->namei != BADCOM)
			ft_printf("%s\n", lem->map_string);
	}
	else if (lem->flag != VALIDATOR)
		ft_printf("%s\n", lem->map_string);
	free(lem->map_string);
	lem->map_string = NULL;
	lem->namei = NEUTRAL;
}

t_lem			*ft_read_and_validate(t_lem *lem)
{
	int			condition;

	while ((condition = get_next_line(0, &lem->map_string)) == GNL_CONTINUE)
	{
		ft_validator(lem);
		ft_print_string_and_free(lem);
	}
	if (condition == GNL_ERROR)
		ft_error(lem);
	return (lem);
}
