# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 16:17:24 by sbronwyn          #+#    #+#              #
#    Updated: 2021/10/26 13:52:20 by sbronwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKS = -I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGL -framework Appkit

SRC = so_long.c utils.c map.c moves.c drawing.c

RM = rm -rf

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(CC) $(CFLAGS) $(LINKS) -o $@ $(SRC:.c=.o)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRC:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean