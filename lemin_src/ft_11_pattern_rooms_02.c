/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_11_pattern_rooms_02.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:45:31 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/28 11:45:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

void			ft_set_start_and_end_room(t_lem *lem)
{
	if (lem->start == WAITING)
	{
		lem->room_start = TRUE;
		lem->start = TRUE;
	}
	else if (lem->end == WAITING)
	{
		lem->room_end = TRUE;
		lem->end = TRUE;
	}
}

int				ft_is_room_pattern(t_lem *lem)
{
	char		*str;

	str = lem->map_string;
	if (ft_strlen(str) < 5)
		return (FALSE);
	if (ft_strchr_qt(str, ' ') != 2)
		return (FALSE);
	while (*str)
	{
		if (*str == ' ' && *(str + 1) == ' ')
			return (FALSE);
		str++;
		if (*str == '\0')
			break ;
	}
	return (TRUE);
}

void			ft_free_and_null(char **str)
{
	if (*str == NULL)
		return ;
	free(*str);
	*str = NULL;
}

char			*ft_set_room_validator_name(t_lem *lem)
{
	char		*result;
	char		*temp1;
	char		*temp2;
	char		*x_cor;
	char		*y_cor;

	x_cor = ft_itoa(lem->x_room);
	y_cor = ft_itoa(lem->y_room);
	temp1 = ft_strjoin("room \"", lem->room_name);
	temp2 = ft_strjoin(temp1, "\", ");
	result = ft_strjoin(temp2, "x = ");
	ft_free_and_null(&temp1);
	ft_free_and_null(&temp2);
	temp1 = ft_strjoin(result, x_cor);
	ft_free_and_null(&result);
	temp2 = ft_strjoin(temp1, ", y = ");
	result = ft_strjoin(temp2, y_cor);
	ft_free_and_null(&temp1);
	ft_free_and_null(&temp2);
	ft_free_and_null(&x_cor);
	ft_free_and_null(&y_cor);
	return (result);
}
