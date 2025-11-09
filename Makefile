# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 21:06:49 by biphuyal          #+#    #+#              #
#    Updated: 2025/11/08 23:33:56 by biphuyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = core/free.c core/game.c core/main.c core/map.c core/map_validation.c core/player.c core/strv.c core/image.c core/utils.c \
	   libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
	   libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
	   libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c \
	   libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c libft/ft_atoi.c \
	   libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c \
	   libft/ft_itoa.c libft/ft_strmapi.c libft/ft_strcmp.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	   libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c \
	   libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c libft/get_next_line.c

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
