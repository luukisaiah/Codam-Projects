# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:    :+:            #
#                                                     +:+ +:+         +:+      #
#    By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 18:07:36 by doda-cun          #+#    #+#              #
#    Updated: 2025/12/02 12:52:25 by lderks         ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_DIR			= ./libft
LIBFT_A				= $(LIBFT_DIR)/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(INC) -I$(LIBFT_DIR)
LIBS = -lreadline

SRCS = main.c $(shell find $(SRC_DIR) -name "*.c")

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LIBS) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
