# Nom de la bibliotheque a generer
NAME = libft.a

# Options de compilations
CFLAGS = -Wall -Wextra -Werror -Ignl/

# Liste des fichiers sources
SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
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