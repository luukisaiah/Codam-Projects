NAME = push_swap

LIBFT_DIR = libft
SRC_DIR = srcs
OBJ_DIR = obj
INCLUDES = incl

SRC = 	$(SRC_DIR)/ps_main.c		\
		$(SRC_DIR)/ps_initialize.c	\
		$(SRC_DIR)/ps_algorithm.c	\
		$(SRC_DIR)/ps_extra.c		\
		$(SRC_DIR)/ps_push.c		\
		$(SRC_DIR)/ps_swap.c		\
		$(SRC_DIR)/ps_rotate.c		\
		$(SRC_DIR)/ps_small_sort.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR)/incl -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
