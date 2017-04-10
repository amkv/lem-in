# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 10:46:14 by akalmyko          #+#    #+#              #
#    Updated: 2017/03/11 19:54:39 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re lib_clean lem_clean lib_fclean lem_fclean lem

NAME = lem-in
LEMIN_F = lemin_src
LIBFT_F = libft/
OBJ_F = obj
LIBFT_L = $(LIBFT_F)libft.a
RMS = /bin/rm -rf
CCFLAGS = -Wall -Wextra -Werror
CC = gcc $(CCFLAGS)
GRN = \033[1;32m
RED = \033[1;31m
WHT = \033[1;37m
CLN = \033[m

CFILES = $(shell find $(LEMIN_F) -type f -follow -print | grep "\.c")
OFILES = $(CFILES:$(LEMIN_F)/%.c=%.o)

all: $(LIBFT_L) $(NAME)

$(LIBFT_L):
	@make -C $(LIBFT_F)

$(NAME):
	@if [ ! -e $(LIBFT_L) ]; then \
		echo "$(RED)libft does not exist$(CLN)"; \
		make -C $(LIBFT_F); \
	fi
	@echo "$(NAME) compiling... \c"
	@$(CC) -c $(CFILES)
	@$(CC) $(OFILES) $(LIBFT_L) -o $(NAME)
	@if [ -e $(NAME) ]; then \
		echo "$(GRN)created$(CLN)";\
	else \
		echo "$(RED)ERROR$(CLN)";\
	fi

clean: lib_clean lem_clean

lib_clean:
	@make -C $(LIBFT_F) clean

lem_clean:
	@echo "$(NAME) cleaning... \c"
	@$(RMS) $(OFILES)
	@echo "$(WHT)cleaned$(CLN)"

fclean: lib_fclean lem_fclean

lib_fclean:
	@make -C $(LIBFT_F) fclean

lem_fclean:
	@echo "$(NAME) fcleaning... \c"
	@$(RMS) $(OFILES)
	@$(RMS) $(NAME)
	@echo "$(WHT)fcleaned$(CLN)"

re: fclean all

lem: lem_fclean $(NAME) lem_clean
