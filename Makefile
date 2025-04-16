# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/04/16 14:29:08 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = Project
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -Ilib/libft -g -g3
LDFLAGS = -Llib/libft -lft

# Dossiers
SRC = src/
OBJ_DIR = obj/
BIN = bin/
LIB = lib/
LIBFT_DIR = $(LIB)libft/

# Repository Libft
LIBFT_REPO = git@github.com:Dradoke/libft.git

# Fichiers sources et objets
SRCS =	$(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Default target
all: clone_libft $(LIBFT_DIR)libft.a $(BIN)$(NAME)

# Cloner Libft dans lib/ s'il n'existe pas
clone_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Libft has landed 🚀"; \
		mkdir -p $(LIB); \
		git clone --quiet $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

# Compiler Libft
$(LIBFT_DIR)libft.a:
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Glory master $(notdir $@) 👑"

# Compiler FDF
$(BIN)$(NAME): $(OBJS) $(LIBFT_DIR)libft.a
	@mkdir -p $(BIN)
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@echo "fdf in the house 🏠"

# Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Good morning mister $(notdir $@) 🫡"

# Nettoyage des fichiers objets et libft
clean:
	@rm -rf $(OBJ_DIR) $(LIB)
	@echo "Farewell, brave objects 😢"

# Nettoyage complet (supprime aussi l’exécutable)
fclean: clean
	@rm -rf $(BIN)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re clone_libft
