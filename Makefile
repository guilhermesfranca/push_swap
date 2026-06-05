# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 11:20:54 by guicarva          #+#    #+#              #
#    Updated: 2026/06/05 20:14:08 by guicarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g

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
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
