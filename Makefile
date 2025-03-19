# Nom de la bibliotheque a generer
NAME = libft.a

# Options de compilations
CFLAGS = -Wall -Wextra -Werror -Ignl/

# Liste des fichiers sources
SRCS = src/ft_isalpha.c \
	src/ft_isdigit.c \
	src/ft_isalnum.c \
	src/ft_isascii.c \
	src/ft_isprint.c \
	src/ft_strlen.c \
	src/ft_memset.c \
	src/ft_bzero.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_strlcpy.c \
	src/ft_strlcat.c \
	src/ft_toupper.c \
	src/ft_tolower.c \
	src/ft_strchr.c \
	src/ft_strrchr.c \
	src/ft_strncmp.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_strnstr.c \
	src/ft_atoi.c \
	src/ft_calloc.c \
	src/ft_strdup.c \
	src/ft_substr.c \
	src/ft_strjoin.c \
	src/ft_strtrim.c \
	src/ft_split.c \
	src/ft_itoa.c \
	src/ft_strmapi.c \
	src/ft_striteri.c \
	src/ft_putchar_fd.c \
	src/ft_putstr_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c
# Liste des fichiers sources BONUS
# BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# 		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
# 		ft_lstmap.c
# Liste des fichiers Objets creer a partir de 'SRCS' (Fichiers sources)
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
PRINTF_OBJS = $(shell find $(PRINTF_DIR) -name '*.o')

OBJ_DIR = obj/
PRINTF_DIR = printf/
PRINTF_LIB = $(PRINTF_DIR)libftprintf.a
# Liste des fichiers Objets BONUS creer a partir de 'BONUS_SRCS' (Fichiers sources)
# BONUS_OBJ = $(BONUS_SRCS:.c=.o)

# Commande pour supprimer des fichiers avec option -f (pas d'erreur)
RM = rm -f

all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

# test/test.a
$(NAME) : $(OBJS) $(PRINTF_LIB)
	@ar rcs $@ $(OBJS) $(PRINTF_OBJS)
#	@ar x test/test.a
#	@ar rcs $(NAME) *.o
#	@rm -f *.o
	@echo "$(NAME) created"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -c $(CFLAGS) $< -o $@

# bonus:		$(BONUS_FILES)
# 	@gcc -c $(FLAG) $(BONUS_FILES)
# 	@ar rcs $(NAME) $(BONUS_OBJ)
# 	@ranlib $(NAME)
printf:
	@make -C printf

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make -C $(PRINTF_DIR) clean
# $(BONUS_OBJ)
	@echo "OBJ deleted"

fclean:		clean
	@$(RM) $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "$(NAME) deleted"

re:	fclean all

.PHONY: all clean fclean re