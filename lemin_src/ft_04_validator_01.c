/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:21:14 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/09 13:21:16 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

void			ft_print_dicision(t_lem *lem)
{
	int			length;
	int			str_len;
	int			spaces;
	char		*errmess;
	char		*name;

	if (lem->flag != VALIDATOR)
		return ;
	length = 35;
	str_len = (int)ft_strlen(lem->map_string);
	if (str_len > length)
		str_len = length;
	if (lem->non_print == 0)
		spaces = length - str_len;
	else
		spaces = length - str_len + lem->non_print;
	errmess = lem->i_message;
	name = "\n";
	if (lem->n_mal == TRUE)
		name = lem->name;
	if (lem->i_err == TRUE)
		ft_printf("%s%*s%s", lem->map_string, spaces, RED"[x] "CLN, errmess);
	else
		ft_printf("%s%*s%s", lem->map_string, spaces, GRY"[ ] "CLN, name);
}

static void		ft_free_room_names(t_lem *lem)
{
	if (lem->room_name_ml == TRUE)
	{
		ft_free_and_null(&lem->room_name);
		lem->room_name_ml = FALSE;
	}
	if (lem->room1_ml == TRUE)
	{
		ft_free_and_null(&lem->room1);
		lem->room1_ml = FALSE;
	}
	if (lem->room2_ml == TRUE)
	{
		ft_free_and_null(&lem->room2);
		lem->room2_ml = FALSE;
	}
}

static void		ft_reinitialize(t_lem *lem)
{
	lem->a_err = FALSE;
	lem->s_err = FALSE;
	lem->e_err = FALSE;
	lem->c_err = FALSE;
	lem->r_err = FALSE;
	lem->l_err = FALSE;
	lem->i_err = FALSE;
	lem->b_err = FALSE;
	lem->non_print = 0;
	lem->x_room = 0;
	lem->y_room = 0;
	ft_free_room_names(lem);
	ft_free_pattern_name_and_errmess(lem);
}

static void		ft_make_a_decision(t_lem *lem)
{
	int			errors;

	errors = 0;
	(lem->c_err == TRUE) ? (errors++) : (errors);
	(lem->a_err == TRUE) ? (errors++) : (errors);
	(lem->s_err == TRUE) ? (errors++) : (errors);
	(lem->e_err == TRUE) ? (errors++) : (errors);
	(lem->r_err == TRUE) ? (errors++) : (errors);
	(lem->l_err == TRUE) ? (errors++) : (errors);
	(lem->b_err == TRUE) ? (errors++) : (errors);
	(lem->i_err == TRUE) ? (lem->glob_err = TRUE) : (lem->glob_err);
	(errors >= 7) ? (lem->glob_err = TRUE) : (lem->glob_err);
	(errors <= 5) ? (lem->glob_err = TRUE) : (lem->glob_err);
	if (lem->glob_err == TRUE && lem->i_mal == FALSE && lem->n_mal == FALSE)
		ft_set_errmess(lem, "err");
	if (lem->flag == VALIDATOR)
		ft_print_dicision(lem);
	if (lem->glob_err == TRUE && lem->flag != VALIDATOR)
		ft_error(lem);
}

void			ft_validator(t_lem *lem)
{
	ft_check_invalid(lem);
	ft_check_comment(lem);
	ft_check_ants(lem);
	ft_check_start(lem);
	ft_check_end(lem);
	ft_check_room(lem);
	ft_check_links(lem);
	ft_check_bad_command(lem);
	ft_make_a_decision(lem);
	ft_add_line(lem);
	if (ft_check_link_doubles(lem->line) == 1)
	{
		ft_set_errmess(lem, "repeated link");
		ft_print_dicision(lem);
		ft_error(lem);
	}
	if (ft_check_room_doubles(lem->line) == 1)
	{
		ft_set_errmess(lem, "repeated room name");
		ft_print_dicision(lem);
		ft_error(lem);
	}
	ft_reinitialize(lem);
}
