# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 14:41:04 by ngaudoui          #+#    #+#              #
#    Updated: 2025/08/17 01:27:54 by ngaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -g -g3
LDFLAGS =
# -fsanitize=address
# -fsanitize=thread

# Dossiers
SRC_DIR = src/
OBJ_DIR = obj/
BIN = bin/



# Fichiers sources et objets
SRCS	=	$(SRC)

SRC		=	$(addprefix $(SRC_DIR)/, \
			init_structs.c	\
			philo_utils.c	\
			philo.c			\
			routine_utils.c	\
			routine_utils2.c\
			routine.c		\
			utils.c			\
			utils2.c		\
		)

OBJS		=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Default target
all: $(BIN)$(NAME)

# Compile project
$(BIN)$(NAME): $(OBJS)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage complet (supprime aussi l’exécutable)
fclean: clean
	rm -rf $(BIN)

# Rebuild from zero
re: fclean all

.PHONY: all clean fclean re
