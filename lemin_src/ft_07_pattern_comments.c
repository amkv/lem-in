/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_07_comments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:43:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 18:43:20 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

int				ft_is_comment_pattern(t_lem *lem)
{
	size_t		len;

	len = ft_strlen(lem->map_string);
	if (len == 0)
		return (FALSE);
	if (len == 1)
	{
		if (*lem->map_string == '#')
			return (TRUE);
		else
			return (FALSE);
	}
	if (*lem->map_string == '#' && *(lem->map_string + 1) != '#')
		return (TRUE);
	else
		return (FALSE);
}

static void		ft_set_comment_and_comment_name(t_lem *lem)
{
	char		*temp;
	char		*message;

	lem->comments++;
	temp = ft_itoa(lem->comments);
	message = ft_strjoin("#comment ", temp);
	ft_free_and_null(&temp);
	ft_set_pattern_name(lem, COMMENT, message);
	ft_free_and_null(&message);
}

static void		ft_set_comment_error(t_lem *lem)
{
	lem->c_err = TRUE;
}

void			ft_check_comment(t_lem *lem)
{
	if (lem->namei != NEUTRAL)
		return (ft_set_comment_error(lem));
	if (ft_is_comment_pattern(lem) == FALSE)
		return (ft_set_comment_error(lem));
	ft_set_comment_and_comment_name(lem);
}
