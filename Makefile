# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 21:26:43 by pgobeil-          #+#    #+#              #
#    Updated: 2019/11/24 00:29:17 by pgobeil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC := main.c utils.c fractals.c

SRCDIR := ./srcs

OBJDIR := objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

HEADER := -I minilibx_macos -I libft -I includes

MLIBXDIR := ./minilibx_macos

FRAME := -framework OpenGL -framework AppKit

LIBFTDIR := ./libft

CC := gcc

CFLAGS := -Wall -Werror -Wextra -c -g -O3

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): OBJS
		$(CC) $(OBJS) -o $(NAME) $(HEADER) -L $(LIBFTDIR) -lft -L $(MLIBXDIR) -lmlx $(FRAME)

OBJS: LIB
		mkdir $(OBJDIR)
		$(CC) $(CFLAGS) $(SRCS) $(HEADER)
		mv *.o $(OBJDIR)

LIB:
	make -C $(LIBFTDIR)
	make -C $(MLIBXDIR)
	rm -rf $(OBJDIR)

clean:
	make -C $(LIBFTDIR) clean
	make -C $(MLIBXDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
		make -C $(LIBFTDIR) fclean
		make -C $(MLIBXDIR) clean
		rm -f $(NAME)

re: fclean all
