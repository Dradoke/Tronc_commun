# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/04/02 18:40:10 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus
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
SRCS_CLIENT = 			$(SRC)client.c \
						$(SRC)utils.c
SRCS_CLIENT_BONUS = 	$(SRC)client_bonus.c \
						$(SRC)utils_bonus.c

SRCS_SERVER =			$(SRC)server.c \
						$(SRC)utils.c
SRCS_SERVER_BONUS =		$(SRC)server_bonus.c \
						$(SRC)utils_bonus.c
OBJS_CLIENT = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS_CLIENT))
OBJS_CLIENT_BONUS = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS_CLIENT_BONUS))

OBJS_SERVER = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS_SERVER))
OBJS_SERVER_BONUS = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS_SERVER_BONUS))
# Default target
all:	clone_libft $(LIBFT_DIR)libft.a $(SERVER) $(CLIENT)
bonus:	clone_libft $(LIBFT_DIR)libft.a $(SERVER_BONUS) $(CLIENT_BONUS)

# Compiler Libft
$(LIBFT_DIR)libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Compiler FDF
$(SERVER): $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) $(LDFLAGS) -o $@
$(SERVER_BONUS):  $(OBJS_SERVER_BONUS)
	$(CC) $(OBJS_SERVER_BONUS) $(LDFLAGS) -o $@

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) $(LDFLAGS) -o $@
$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(OBJS_CLIENT_BONUS) $(LDFLAGS) -o $@

# Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cloner Libft dans lib/ s'il n'existe pas
clone_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning libft into lib/..."; \
		mkdir -p $(LIB); \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

# Nettoyage des fichiers objets et libft
clean:
	rm -rf $(OBJ_DIR) $(LIB)

# Nettoyage complet (supprime aussi l’exécutable)
fclean: clean
	rm -rf $(SERVER) $(SERVER_BONUS) $(CLIENT) $(CLIENT_BONUS)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re clone_libft
