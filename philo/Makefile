# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/04/10 16:22:08 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -g -g3 -fsanitize=thread
# -fsanitize=address 

# Dossiers
SRC = src/
OBJ_DIR = obj/
BIN = bin/

# Fichiers sources et objets
SRCS = $(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Default target
all: $(BIN)$(NAME)

# Compile project
$(BIN)$(NAME): $(OBJS)
	@mkdir -p $(BIN)
	$(CC) $(OBJS) -o $@

# Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage complet (supprime aussi l’exécutable)
fclean: clean
	rm -rf $(BIN)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re
