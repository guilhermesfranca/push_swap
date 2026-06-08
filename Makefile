# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 11:20:54 by guicarva          #+#    #+#              #
#    Updated: 2026/06/07 15:12:33 by guicarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g
MKDIR    = mkdir -p

SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = includes

RM = rm -rf

SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME)

#  python3 -m ft_ps_tester ./push_swap
run: all
	./push_swap 2 1 3

re: fclean all

.PHONY: all clean fclean re
