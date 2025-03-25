# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/03/25 11:48:43 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -Iminilibx/ -Ilib/libft-g -g3
LDFLAGS = -Llib/libft -Lminilibx -lmlx_Linux -lm -lXext -lX11 -lz -lft

# Dossiers
SRC = src/
OBJ_DIR = obj/
BIN = bin/
LIB = lib/
LIBFT_DIR = $(LIB)libft/
MINILIBX = minilibx/

# Repository Libft
LIBFT_REPO = git@github.com:Dradoke/libft.git

# Fichiers sources et objets
SRCS = $(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS))

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
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et libft
clean:
	rm -rf $(OBJ_DIR) $(LIB)

# Nettoyage complet (supprime aussi l’exécutable)
fclean: clean
	rm -rf $(BIN)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re clone_libft
