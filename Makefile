# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 14:49:37 by miguel-f          #+#    #+#              #
#    Updated: 2025/06/05 12:53:49 by miguel-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Sources
SRCS =	src/main.c src/utils.c src/parsing.c \
		src/operations/push.c src/operations/swap.c \
		src/operations/rotate.c src/operations/reverse_rotate.c \
		src/utils_verify.c src/algorithm/special_cases.c \
		src/algorithm/cost_algorithm.c src/algorithm/utils_math.c \
		src/algorithm/cost_calculation.c src/algorithm/cost_execution.c
OBJS = $(SRCS:.c=.o)

# Command cleaner
RM = rm -f

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Rules
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c src/push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re