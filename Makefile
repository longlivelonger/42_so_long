# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 16:17:24 by sbronwyn          #+#    #+#              #
#    Updated: 2021/11/04 16:28:22 by sbronwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft
LINKS = -I /usr/local/include -L /usr/local/lib -l mlx \
		-I libft -L libft -l ft -framework OpenGL -framework Appkit

SRC = so_long.c utils.c map.c moves.c drawing.c

LIBFT = libft/libft.a

RM = rm -rf

all: $(NAME)

$(NAME): $(SRC:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) $(LINKS) -o $@ $(SRC:.c=.o)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C libft clean
	$(RM) $(SRC:.c=.o)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

$(LIBFT):
	make -C libft bonus

.PHONY: all re clean fclean