# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                            :+:    :+:            #
#                                                      +:+                     #
#    By: lderks <lderks@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/06/16 18:07:36 by doda-cun      #+#    #+#                  #
#    Updated: 2025/12/19 14:57:23 by lderks         ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

NAME		= philo
INC			= inc/
SRC_DIR		= srcs/
OBJ_DIR		= obj/

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -pthread -g -I$(INC)
LIBS		= -pthread

SRCS =	$(SRC_DIR)main.c \
		$(SRC_DIR)error_handling/check_input.c \
		$(SRC_DIR)error_handling/handle_error_all.c \
		$(SRC_DIR)error_handling/handle_error_forks.c \
		$(SRC_DIR)error_handling/handle_error_program.c \
		$(SRC_DIR)initialize/initialize_all.c \
		$(SRC_DIR)initialize/initialize_forks.c \
		$(SRC_DIR)initialize/initialize_philosophers.c \
		$(SRC_DIR)initialize/initialize_program.c \
		$(SRC_DIR)initialize/setup_start_threads.c \
		$(SRC_DIR)monitor_philos/check_eat_count.c \
		$(SRC_DIR)monitor_philos/check_philo_dead.c \
		$(SRC_DIR)monitor_philos/check_ttdie_philos.c \
		$(SRC_DIR)monitor_philos/monitor_philos.c \
		$(SRC_DIR)philo_cycle/eat_cycle.c \
		$(SRC_DIR)philo_cycle/philo_cycle.c \
		$(SRC_DIR)philo_cycle/sleep_cycle.c \
		$(SRC_DIR)philo_cycle/think_cycle.c \
		$(SRC_DIR)utils/utils_nbr.c \
		$(SRC_DIR)utils/utils_print.c \
		$(SRC_DIR)utils/utils_time.c

OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
