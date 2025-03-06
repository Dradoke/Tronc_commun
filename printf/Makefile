# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 21:57:55 by jmilesi           #+#    #+#              #
#    Updated: 2025/03/06 14:12:30 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ_DIR = ../obj/printf/
SRC_DIR = ./ 

SRC = ft_printf.c ft_putnbr_base.c ft_printf_cspct.c

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

OBJS = $(SRC:.c=.o)

all: $(NAME) move_objs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) created"

move_objs:
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJS) $(OBJ_DIR)
	$(RM) $(NAME)
	@echo "Objects moved to $(OBJ_DIR)"


clean:
	$(RM) $(OBJS)
	@echo "Printf OBJ deleted"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) deleted"

re: fclean $(NAME)

.PHONY: all clean fclean re move_objs