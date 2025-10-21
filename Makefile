# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 21:06:49 by biphuyal          #+#    #+#              #
#    Updated: 2025/10/21 16:58:33 by biphuyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = core/game.c core/map-array.c core/checks.c core/error.c core/free.c core/hooks.c \
	   libft/get_next_line.c libft/ft_strjoin.c libft/ft_split.c libft/ft_strlcpy.c libft/ft_strdup.c
OBJS = $(SRCS:.c=.o)
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -I.
else
	INCLUDES = -I/opt/X11/include -I.
endif

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -L. -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -L. -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif


all: libmlx.a $(NAME)

libmlx.a:
	tar -xvf minilibx-linux.tgz
	cd minilibx-linux && make && cp libmlx*.a .. && cp mlx.h ..
	rm -rf minilibx-linux

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f libmlx*.a mlx.h

re: fclean all

.PHONY: all clean fclean re
