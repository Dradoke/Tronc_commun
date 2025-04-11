# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/04/11 12:21:03 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -Ilib/libft -g -g3
LDFLAGS = -Llib/libft -lft

# Dossiers
SRC = src/
OBJ_DIR = obj/
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

# Mode de compilation (normal / bonus)
ifeq ($(MAKECMDGOALS), bonus)
	SRCS_CLIENT_USED = $(SRCS_CLIENT_BONUS)
	SRCS_SERVER_USED = $(SRCS_SERVER_BONUS)
else
	SRCS_CLIENT_USED = $(SRCS_CLIENT)
	SRCS_SERVER_USED = $(SRCS_SERVER)
endif

OBJS_CLIENT_USED = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS_CLIENT_USED))
OBJS_SERVER_USED = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SRCS_SERVER_USED))

# Default target
NAME = client server
all:	clone_libft $(NAME)

bonus:	clone_libft $(SERVER_BONUS) $(CLIENT_BONUS)

# Compiler Libft
$(LIBFT_DIR)libft.a:
	@if [ ! -f "$(LIBFT_DIR)libft.a" ]; then \
		echo "Building libft..."; \
		$(MAKE) -C $(LIBFT_DIR); \
	else \
		echo "libft.a already built."; \
	fi

# Compiler client et server
$(SERVER):$(OBJS_SERVER_USED) $(LIBFT_DIR)libft.a
	@if ! test -f $(SERVER); then \
		$(CC) $(OBJS_SERVER_USED) $(LDFLAGS) -o $(SERVER); \
	else \
		echo "$(SERVER) is already up to date."; \
	fi

$(CLIENT):$(OBJS_CLIENT_USED) $(LIBFT_DIR)libft.a
	@if ! test -f $(CLIENT); then \
		$(CC) $(OBJS_CLIENT_USED) $(LDFLAGS) -o $(CLIENT); \
	else \
		echo "$(CLIENT) is already up to date."; \
	fi
# Compiler client et server
$(SERVER_BONUS):$(OBJS_SERVER_USED) $(LIBFT_DIR)libft.a
	@if ! test -f $(SERVER); then \
		$(CC) $(OBJS_SERVER_USED) $(LDFLAGS) -o $(SERVER); \
	else \
		echo "$(SERVER_BONUS) is already up to date."; \
	fi

$(CLIENT_BONUS):$(OBJS_CLIENT_USED) $(LIBFT_DIR)libft.a
	@if ! test -f $(CLIENT); then \
		$(CC) $(OBJS_CLIENT_USED) $(LDFLAGS) -o $(CLIENT); \
	else \
		echo "$(CLIENT_BONUS) is already up to date."; \
	fi
# Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC)%.c | clone_libft
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

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
	rm -rf $(SERVER) $(CLIENT)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re bonus client server
