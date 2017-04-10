/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_02_set_lem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:16:12 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/22 15:16:16 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

static void		ft_set_validator(t_lem *lem)
{
	lem->ants = 0;
	lem->a_true = FALSE;
	lem->a_err = FALSE;
	lem->start = FALSE;
	lem->s_true = FALSE;
	lem->s_err = FALSE;
	lem->end = FALSE;
	lem->e_true = FALSE;
	lem->e_err = FALSE;
	lem->comments = 0;
	lem->c_true = FALSE;
	lem->c_err = FALSE;
	lem->rooms = 0;
	lem->r_true = FALSE;
	lem->r_err = FALSE;
	lem->links = 0;
	lem->l_true = FALSE;
	lem->l_err = FALSE;
	lem->i_err = FALSE;
	lem->b_err = FALSE;
	lem->b_true = FALSE;
	lem->glob_err = FALSE;
	lem->room_start = FALSE;
	lem->room_end = FALSE;
}

static t_lem	*ft_new_lem(void)
{
	t_lem		*lem;

	lem = (t_lem*)malloc(sizeof(t_lem) * 1);
	if (!lem)
		return (NULL);
	ft_set_validator(lem);
	lem->map_string = NULL;
	lem->i_message = NULL;
	lem->flag = NEUTRAL;
	lem->non_print = 0;
	lem->i_mal = FALSE;
	lem->name = NULL;
	lem->n_mal = FALSE;
	lem->namei = NEUTRAL;
	lem->line = NULL;
	lem->room_name = NULL;
	lem->room_name_ml = FALSE;
	lem->x_room = 0;
	lem->y_room = 0;
	lem->room1 = NULL;
	lem->room2 = NULL;
	lem->room1_ml = FALSE;
	lem->room2_ml = FALSE;
	return (lem);
}

static void		ft_check_the_flag(char *argv, t_lem *lem)
{
	int			(*cmp)(const char *, const char *);

	cmp = &ft_strcmp;
	if (cmp(argv, "h") == EQUAL || cmp(argv, "-help") == EQUAL)
		lem->flag = HELP;
	else if (cmp(argv, "s") == EQUAL || cmp(argv, "-shortpath") == EQUAL)
		lem->flag = SHORTPATH;
	else if (cmp(argv, "v") == EQUAL || cmp(argv, "-validator") == EQUAL)
		lem->flag = VALIDATOR;
	else if (cmp(argv, "l") == EQUAL || cmp(argv, "-lasterror") == EQUAL)
		lem->flag = LASTERROR;
	else if (cmp(argv, "c") == EQUAL || cmp(argv, "-nocomment") == EQUAL)
		lem->flag = NOCOMMENT;
	else if (cmp(argv, "p") == EQUAL || cmp(argv, "-patterns") == EQUAL)
		lem->flag = PATTERNS;
	else if (cmp(argv, "i") == EQUAL || cmp(argv, "-links") == EQUAL)
		lem->flag = PATHES;
	else
		ft_error(lem);
}

void			set_lem(int argc, char *argv, t_lem **lem)
{
	*lem = ft_new_lem();
	if (argc == 1)
		return ;
	if (*argv == '-')
	{
		argv++;
		ft_check_the_flag(argv, *lem);
		if ((*lem)->flag == HELP)
			ft_print_usage(*lem);
	}
	else
		ft_error(*lem);
}
