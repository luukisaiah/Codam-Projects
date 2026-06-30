NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I$(MLX_DIR)/include -I./incl -I./libft -O3
LDFLAGS = -L./libft -L./MLX42/build -lmlx42 -lX11 -ldl -lglfw -pthread -lft

MLX_REPO = https://github.com/codam-coding-college/MLX42.git

MLX_DIR = ./MLX42
MLX_BUILD = $(MLX_DIR)/build/libmlx42.a
MLX_HEADER = $(MLX_DIR)/include/MLX42/MLX42.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	srcs/main.c srcs/utils.c srcs/build_map.c srcs/check_map_elem.c srcs/check_map_path.c srcs/image_loading.c srcs/initialize_map.c srcs/my_hooks.c srcs/update_map.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: check_mlx $(NAME) 

check_mlx:
	@if [ ! -f "$(MLX_HEADER)" ]; then \
		echo "MLX42.h not found! Reinstalling MLX42..."; \
		rm -rf $(MLX_DIR); \
 		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@make -C $(MLX_DIR)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MLX_BUILD) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re check_mlx
