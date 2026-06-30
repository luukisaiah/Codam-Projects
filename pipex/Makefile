NAME = pipex

LIBFT_DIR = libft
SRC_DIR = srcs
OBJ_DIR = objects
INCLUDES = includes
	
SRC =	$(SRC_DIR)/pipex.c				\
		$(SRC_DIR)/envp_func.c			\
		$(SRC_DIR)/pipex_utils.c		\
		$(SRC_DIR)/pipex_split_utils.c	\
		$(SRC_DIR)/pipex_split.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

HEADERS = $(INCLUDES)/pipex.h $(INCLUDES)/libft.h

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR)/includes -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) libft.a
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
