/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_09_final_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:03:19 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/25 14:03:20 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void		ft_print_final_errors(t_lem *lem)
{
	if (lem->rooms == 0 || lem->links == 0)
	{
		if (lem->rooms == 0)
			ft_set_errmess(lem, "no rooms");
		if (lem->links == 0)
			ft_set_errmess(lem, "no links");
		ft_print_dicision(lem);
		ft_error(lem);
	}
}

static void		ft_print_patterns(t_line *line)
{
	t_line		*ln;
	char		*name;
	int			index;

	if (!line)
		return ;
	ln = line->holder;
	index = 1;
	ft_printf("\n");
	while (ln)
	{
		name = NULL;
		(ln->type == COMMENT) ? (name = "#comment") : (name);
		(ln->type == ANTS) ? (name = "ants") : (name);
		(ln->type == START) ? (name = "##start") : (name);
		(ln->type == END) ? (name = "##end") : (name);
		(ln->type == ROOM) ? (name = "room") : (name);
		(ln->type == LINKS) ? (name = "link") : (name);
		(ln->type == BADCOM) ? (name = "#badcom") : (name);
		ft_printf("%d. %s\n", index++, name);
		ln = ln->next;
	}
}

t_line			*ft_final_validation(t_lem *lem)
{
	if (lem->glob_err == TRUE)
		ft_error(lem);
	if (lem->flag == VALIDATOR)
		ft_print_final_errors(lem);
	else if (lem->rooms == 0 || lem->links == 0)
		ft_error(lem);
	if (lem->flag == PATTERNS)
		ft_print_patterns(lem->line);
	if (lem->line)
		return (lem->line);
	else
		return (NULL);
}
