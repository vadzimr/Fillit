# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrayinch <vrayinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 19:09:48 by echeung           #+#    #+#              #
#    Updated: 2020/02/20 21:04:02 by vrayinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read_and_valid.c dot_to_arr.c print_board.c solver.c

OBJ = *.o

HEADER = fillit.h

LIBFT = libft/

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAG) -o $(NAME) $(SRC) -I$(HEADER) -g -L. libft/libft.a

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
