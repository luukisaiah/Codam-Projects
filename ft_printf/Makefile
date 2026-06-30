NAME = libftprintf.a

LIBFT_DIR = libft
SRC_DIR = srcs
OBJ_DIR =  objects
INCLUDES = includes

SRC = 	$(SRC_DIR)/ft_printf.c			\
		$(SRC_DIR)/ft_printstring.c		\
		$(SRC_DIR)/ft_printpointer.c	\
		$(SRC_DIR)/ft_printnbr.c		\
		$(SRC_DIR)/ft_printunsigned.c	\
		$(SRC_DIR)/ft_printhex.c	

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
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR)/includes -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) 
	@cp $(LIBFT) $(NAME)
	$(AR) $@ $(OBJ)

clean:
	$(RM) $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) libft.a
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
