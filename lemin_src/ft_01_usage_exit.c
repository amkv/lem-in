/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_01_usage_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:13:33 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/22 15:13:35 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lheader.h"

void			ft_free_all_part_1(t_lem *lem)
{
	if (lem)
	{
		if (lem->map_string)
			ft_free_and_null(&lem->map_string);
		ft_free_lines(lem);
		ft_free_pattern_name_and_errmess(lem);
		free(lem);
	}
}

void			ft_error(t_lem *lem)
{
	char		*string;
	char		*message;

	string = NULL;
	message = NULL;
	if (lem && lem->map_string)
		string = lem->map_string;
	if (lem && lem->i_message)
		message = lem->i_message;
	if (lem && lem->flag == LASTERROR)
	{
		if (!message)
			ft_printf("%s\n", "ERROR with rooms or links");
		else
			ft_printf("%s "RED"%s"CLN"%s\n", string, message, "ERROR");
	}
	else
		ft_putstr("ERROR\n");
	ft_free_all_part_1(lem);
	exit(EXIT_FAILURE);
}

static void		ft_usage(char *str)
{
	int			border;
	char		sym;
	int			str_len;
	int			remain;
	int			index;

	if (!str)
		return ;
	border = 64;
	sym = '.';
	if (ft_strcmp("border", str) == 0)
	{
		index = 0;
		while (index++ < (border / 2 + 1))
			ft_printf("%c ", sym);
		ft_printf("\n");
	}
	else if (ft_strcmp("line", str) == 0)
		ft_printf("%c%*c%c", sym, border, sym, '\n');
	else
	{
		str_len = (int)ft_strlen(str);
		remain = border - 1 - str_len - 2;
		ft_printf("%c%*s%*c%c", sym, 3 + str_len, str, remain, sym, '\n');
	}
}

void			ft_print_usage(t_lem *lem)
{
	ft_usage("border");
	ft_usage("line");
	ft_usage("usage: ./lem-in [flag] < [text_file]");
	ft_usage("line");
	ft_usage("BONUSES:");
	ft_usage("-h or --help ,show this usage and exit");
	ft_usage("-c or --nocomments ,print the map without comments");
	ft_usage("-v or --validator ,show validator results");
	ft_usage("-l or --lasterror ,show last validator's error");
	ft_usage("-p or --patterns ,show the list of patterns");
	ft_usage("-i or --links ,show all links");
	ft_usage("-s or --shortpath ,show ");
	ft_usage("line");
	ft_usage("border");
	ft_free_all_part_1(lem);
	exit(EXIT_SUCCESS);
}
