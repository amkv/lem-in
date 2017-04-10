/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lheader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:12:03 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/07 15:12:04 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LHEADER_H
# define LHEADER_H
# include "../libft/libft/libft.h"
# define RET_SUCCESS 0
# define RET_FAILURE 1
# define TRUE 1
# define NEUTRAL 0
# define FALSE -1
# define EQUAL 0
# define WAITING 3
# define STARTROOM 4
# define ENDROOM 5
# define NOLINKS 0

# define FLAG 0
# define END_ROOM 1
# define COUNTER 2
# define MIN_STEPS 3
# define INFINITILOOP 4

# define COMMENT 1
# define ANTS 2
# define START 3
# define END 4
# define ROOM 5
# define LINKS 6
# define BADCOM 7

# define LASTERROR 108
# define VALIDATOR 118
# define HELP 104
# define SHORTPATH 115
# define NOCOMMENT 99
# define PATTERNS 112
# define PATHES 105

typedef struct		s_box
{
	int				num;
	char			*room_name;
	struct s_room	*room;
}					t_box;

typedef struct		s_room
{
	int				room_num;
	int				ants;
	int				aname;
	int				marker;
	char			*room_name;
	int				x;
	int				y;
	int				step_num;
	int				visited;
	int				links;
	struct s_room	*holder;
	struct s_room	*next;
	struct s_box	**box;
	struct s_room	*path;
	struct s_room	*path_holder;
	struct s_room	*short_path;
	struct s_room	*short_next;
	struct s_room	*short_holder;
	struct s_room	*short_revers;
	struct s_room	*short_last_holder;
	struct s_room	*revers;
}					t_room;

typedef struct		s_line
{
	int				type;
	char			*str;
	int				value;
	int				x;
	int				y;
	char			*room1;
	char			*room2;
	struct s_line	*holder;
	struct s_line	*next;
}					t_line;

typedef struct		s_lem
{
	char			*map_string;
	char			*i_message;
	char			*name;
	int				namei;
	int				i_mal;
	int				n_mal;
	int				i_err;
	int				c_err;
	int				a_err;
	int				s_err;
	int				e_err;
	int				r_err;
	int				l_err;
	int				b_err;
	int				glob_err;
	int				comments;
	int				ants;
	int				start;
	int				end;
	int				rooms;
	int				links;
	int				c_true;
	int				a_true;
	int				s_true;
	int				e_true;
	int				r_true;
	int				l_true;
	int				b_true;
	int				non_print;
	int				flag;
	char			*room_name;
	int				x_room;
	int				y_room;
	int				room_name_ml;
	char			*room1;
	char			*room2;
	int				room1_ml;
	int				room2_ml;
	int				room_start;
	int				room_end;
	struct s_line	*line;
}					t_lem;

t_lem				*ft_read_and_validate(t_lem *lem);
void				ft_validator(t_lem *lem);
void				ft_error(t_lem *lem);
void				ft_print_usage(t_lem *lem);
void				ft_free_all_part_1(t_lem *lem);
void				set_lem(int argc, char *argv, t_lem **lem);
void				ft_print_lem(t_lem *lem);
void				ft_check_ants(t_lem *lem);
void				ft_check_start(t_lem *lem);
void				ft_check_end(t_lem *lem);
void				ft_check_comment(t_lem *lem);
void				ft_check_room(t_lem *lem);
void				ft_check_links(t_lem *lem);
void				ft_check_invalid(t_lem *lem);
void				ft_check_bad_command(t_lem *lem);
void				ft_set_errmess(t_lem *lem, char *message);
void				ft_set_pattern_name(t_lem *lem, int pattername, char *msg);
void				ft_free_pattern_name_and_errmess(t_lem *lem);
t_line				*ft_final_validation(t_lem *lem);
void				ft_print_dicision(t_lem *lem);
int					ft_is_start_pattern(t_lem *lem);
int					ft_is_end_pattern(t_lem *lem);
int					ft_is_comment_pattern(t_lem *lem);
int					ft_is_room_pattern(t_lem *lem);
char				*ft_set_room_validator_name(t_lem *lem);
void				ft_set_start_and_end_room(t_lem *lem);
int					ft_is_room_name_exist(t_lem *lem, int num);
int					ft_check_room_doubles(t_line *line);
int					ft_check_link_doubles(t_line *line);
void				ft_add_line(t_lem *lem);
void				ft_free_lines(t_lem *lem);
void				ft_free_and_null(char **str);
t_room				*ft_get_rooms(t_line *lines, int flag);
t_room				*ft_create_rooms(t_line *lines, t_room *rooms);
t_room				*ft_create_boxes(t_line *lines, t_room *rooms);
t_room				*ft_find_straight_short_path(t_room *rooms, int flag);
void				ft_print_path(t_room *rooms, int *o);
void				ft_print_short_path(t_room *rooms, int flag, int index);
void				ft_print_links(t_room *rooms);
void				ft_print_straight_trip_of_ants(t_room *path);
void				ft_exit_error(t_room *rooms, t_room *path, int flag);

#endif
