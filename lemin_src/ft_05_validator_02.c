/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_05_validator_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:38:07 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 18:38:08 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

void			ft_set_errmess(t_lem *lem, char *message)
{
	char		*temp;

	if (lem->i_mal == TRUE)
	{
		ft_free_and_null(&lem->i_message);
		lem->i_mal = FALSE;
	}
	lem->i_err = TRUE;
	temp = ft_strdup(message);
	lem->i_message = ft_strjoin(temp, "\n");
	lem->i_mal = TRUE;
	ft_free_and_null(&temp);
}

void			ft_set_pattern_name(t_lem *lem, int patternname, char *msg)
{
	if (lem->n_mal == TRUE)
	{
		ft_free_and_null(&lem->name);
		lem->n_mal = FALSE;
	}
	if (!msg)
		msg = "";
	lem->name = ft_strjoin(msg, "\n");
	lem->n_mal = TRUE;
	lem->namei = patternname;
	(lem->namei == COMMENT) ? (lem->c_true = TRUE) : (lem->c_true);
	(lem->namei == ANTS) ? (lem->a_true = TRUE) : (lem->a_true);
	(lem->namei == START) ? (lem->s_true = TRUE) : (lem->s_true);
	(lem->namei == END) ? (lem->e_true = TRUE) : (lem->e_true);
	(lem->namei == ROOM) ? (lem->r_true = TRUE) : (lem->r_true);
	(lem->namei == LINKS) ? (lem->l_true = TRUE) : (lem->l_true);
	(lem->namei == BADCOM) ? (lem->b_true = TRUE) : (lem->l_true);
}

void			ft_free_pattern_name_and_errmess(t_lem *lem)
{
	if (lem->i_mal == TRUE)
	{
		ft_free_and_null(&lem->i_message);
		lem->i_mal = FALSE;
	}
	if (lem->n_mal == TRUE)
	{
		ft_free_and_null(&lem->name);
		lem->n_mal = FALSE;
	}
}

int				ft_check_link_doubles(t_line *line)
{
	t_line		*ln;
	t_line		*compare;

	ln = line->holder;
	while (ln)
	{
		if (ln->type == LINKS)
		{
			compare = ln->next;
			while (compare)
			{
				if (compare->type == LINKS && ln->room1 && compare->room1)
				{
					if (ft_strcmp(ln->room1, compare->room1) == 0
						&& ft_strcmp(ln->room2, compare->room2) == 0)
						return (1);
				}
				compare = compare->next;
			}
		}
		ln = ln->next;
	}
	return (0);
}

int				ft_check_room_doubles(t_line *line)
{
	t_line		*ln;
	t_line		*compare;

	ln = line->holder;
	while (ln)
	{
		if (ln->type == ROOM)
		{
			compare = ln->next;
			while (compare)
			{
				if (compare->type == ROOM && ln->str && compare->str)
				{
					if (ft_strcmp(ln->str, compare->str) == 0)
						return (1);
				}
				compare = compare->next;
			}
		}
		ln = ln->next;
	}
	return (0);
}
