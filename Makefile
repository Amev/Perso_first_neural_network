# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vame <vame@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 11:23:10 by vame              #+#    #+#              #
#    Updated: 2015/03/02 15:58:32 by vame             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nnw_nb

CFLAGS = -Werror -Wextra -Wall -O3 -I libft/includes/

INC = ./neural_network_1.h

TMP = $(INC:.h=.h.gch)

SRC =	./main.c \
		./tools.c \
		./weight.c \
		./nnw_file.c \
		./file_tools.c

BINAIRE = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@make -C libft/
		gcc -c $(CFLAGS) $(INC) $(SRC)
		gcc -g -o $(NAME) $(BINAIRE) -L libft/ -lft
		@rm -f $(TMP)

lib :
		@make -C libft/ fclean
		@make -C libft/

clean:
		rm -f $(BINAIRE)
		@make -C libft/ clean

fclean: clean
		rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all

.PHONY: all $(NAME) lib clean fclean re
