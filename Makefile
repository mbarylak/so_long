# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 17:07:28 by mbarylak          #+#    #+#              #
#    Updated: 2022/02/14 19:11:57 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = make_map.c ./gnl/get_next_line.c so_long.c movement.c press_key.c \
	   check_map.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MINILIB = -L mlx -l mlx -framework OpenGL -framework AppKit
RM = rm -rf

all: ${NAME}

$(NAME): $(OBJS)
	
	$(CC)  $(OBJS) $(MINILIB) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@make clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re
