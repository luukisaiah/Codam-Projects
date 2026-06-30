# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: lderks <lderks@codam.student.nl>              +#+                     #
#                                                     +#+                      #
#    Created: 2024/10/17 18:45:13 by lderks         #+#    #+#                 #
#    Updated: 2025/02/06 17:48:13 by lderks         ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_strlcat.c	\
		ft_strdup.c		\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_split.c		\
		ft_memcpy.c		\
		ft_substr.c		\
		ft_putstr_fd.c	

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
