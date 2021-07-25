# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 08:53:28 by mlazzare          #+#    #+#              #
#    Updated: 2021/07/25 12:29:41 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract0l

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L./mlx -lmlx -lXext -lX11 -lbsd -L./libft -lft -lm 

HEADER = -I./includes \

SRCS =  \
		./srcs/fractal/start_fractal.c \
		./srcs/fractal/init_fractal.c \
		./srcs/fractal/draw_fractal.c \
		./srcs/utils/free.c \
		./srcs/utils/errors.c \
		./srcs/utils/colors.c \
		./srcs/utils/keys.c \
		./srcs/utils/movements.c \
		./srcs/main.c

OBJS = 	$(SRCS:.c=.o)
MLX = ./mlx/libmlx.a
LIBFT = libft/libft.a

.c.o:
	$(CC) -g -Imlx -O2 -c $< -o $@

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(SRCS) $(CFLAGS) $(LIB) $(HEADER) -o $(NAME)

all:$(NAME)
	
$(LIBFT):
	$(MAKE) -C ./libft

$(MLX):
	$(MAKE) -C ./mlx

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJB)
	@cd libft && make clean
	@cd mlx && make clean

fclean:	clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re:	fclean all

.PHONY:	all clean fclean re
