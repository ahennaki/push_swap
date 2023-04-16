# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 22:16:57 by aennaki           #+#    #+#              #
#    Updated: 2023/03/14 16:20:54 by aennaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
NAME = push_swap
NAME_BNS = checker
CFLAGS = -Wall -Werror -Wextra

SRC = src/push.c src/rev_rotate.c src/rotate.c src/swap.c src/libft.c src/check_input.c \
		src/list_new.c src/position.c src/sort.c src/ft_split.c src/cost_move.c src/exit.c\
		printf/ft_printf.c printf/ft_printfmt.c printf/printf_utils.c \
		gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

SRC_MAN = push_swap.c

OBJ_MAN = $(SRC_MAN:.c=.o)

SRC_BNS = checker.c gnl/get_next_line.c

OBJ_BNS = $(SRC_BNS:.c=.o)

HEADERS = headers/ft_printf.h headers/push_swap.h headers/get_next_line.h

RM = rm -rf

all : $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(OBJ_MAN)
	$(CC) $(CFLAGS) $^ -o $(NAME)

bonus : $(NAME_BNS)

$(NAME_BNS) : $(OBJ) $(OBJ_BNS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BNS)

clean :
	$(RM) $(OBJ) $(OBJ_MAN) $(OBJ_BNS)
	
fclean : clean
	$(RM) $(NAME) $(NAME_BNS)

re : fclean all

.PHONY : all bonus clean fclean re