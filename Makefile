# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilh <guilh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 11:20:54 by guicarva          #+#    #+#              #
#    Updated: 2026/06/21 23:56:23 by guilh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap
BONUS    = checker
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g
MKDIR    = mkdir -p

SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = includes

RM = rm -rf

COMMON_SRCS = \
		srcs/get_next_line.c \
		srcs/sort_turk_utils_2.c \
		srcs/push_swap.c \
		srcs/coisas_que_nao_vão.c \
		srcs/ft_split.c \
		srcs/sort_simple.c \
		srcs/o_push.c \
		srcs/o_rotate.c \
		srcs/utils2.c \
		srcs/o_swap.c \
		srcs/sort_turk.c \
		srcs/ft_printf_utils.c \
		srcs/ft_printf.c \
		srcs/free_and_check.c \
		srcs/get_next_line_utils.c \
		srcs/sort_k.c \
		srcs/o_rotate_r.c \
		srcs/sort_turk_utils_1.c \
		srcs/make_stack.c \
		srcs/utils1.c

PUSH_SWAP_SRCS = $(COMMON_SRCS) srcs/main.c
CHECKER_SRCS   = $(COMMON_SRCS) srcs/checker.c


PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
CHECKER_OBJS   = $(CHECKER_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $@

bonus: $(BONUS)

$(BONUS): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME) $(BONUS)

run: all
	./push_swap 2 1 3

re: fclean all

.PHONY: all clean fclean re bonus
