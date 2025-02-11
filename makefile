# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/02/11 14:41:05 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = fdf
# Compilateur
CC = gcc
# Compilation options 
# !!!!! RAJOUTER WERROR !!!!!
CFLAGS = -Wall -Wextra -Iinclude/ -Iminilibx/ -g
#-lft	# Link options for libs
LDFLAGS = -Llib -Lminilibx -lmlx_Linux -lm -lXext -lX11 -lz
# sources directory
SRC = src/
# objects directory
OBJ = obj/
# Bin directory
BIN = bin/
# Libs directory
LIB = lib
MINILIBX = minilibx/

# Sources files
SRCS = $(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ)%.o, $(SRCS))

# Default target
all: $(BIN)$(NAME)

# Executable target
$(BIN)$(NAME): $(OBJS) #$(LIB)/libft.a
	@mkdir -p $(BIN)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Compiling rules for .c files to .o files
$(OBJ)%.o: $(SRC)%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

#$(LIB)/libft.a:

# Delete obj, bin and lib directories
clean:
	rm -rf $(OBJ) $(LIB)

# Delete bin directory
fclean: clean
	rm -rf $(BIN)

# Rebuild from zero
re: clean $(BIN)$(NAME)

.PHONY: all clean fclean re