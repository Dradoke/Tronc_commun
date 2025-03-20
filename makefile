# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 16:48:01 by ngaudoui          #+#    #+#              #
#    Updated: 2025/03/20 16:48:58 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -Ilib/libft-g
LDFLAGS = -Llib/libft -lft

# Dossiers
SRC = src/
OBJ = obj/
BIN = bin/
LIB = lib/
LIBFT_DIR = $(LIB)libft/

# Repository Libft
LIBFT_REPO = git@github.com:Dradoke/libft.git

# Fichiers sources et objets
SRCS = $(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ)%.o, $(SRCS))

# Default target
all: clone_libft $(LIBFT_DIR)libft.a $(BIN)$(NAME)

# Cloner Libft dans lib/ s'il n'existe pas
clone_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning libft into lib/..."; \
		mkdir -p $(LIB); \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

# Compiler Libft
$(LIBFT_DIR)libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Compiler FDF
$(BIN)$(NAME): $(OBJS) $(LIBFT_DIR)libft.a
	@mkdir -p $(BIN)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Compilation des fichiers .c en .o
$(OBJ)%.o: $(SRC)%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et libft
clean:
	rm -rf $(OBJ) $(LIB)

# Nettoyage complet (supprime aussi l’exécutable)
fclean: clean
	rm -rf $(BIN)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re clone_libft