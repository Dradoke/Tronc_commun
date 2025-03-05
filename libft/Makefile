# Nom de la bibliotheque a generer
NAME = libft.a

# Options de compilations
CFLAGS = -Wall -Wextra -Werror -Ignl/

# Liste des fichiers sources
FILES = ft_isalpha.c \
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
	ft_putnbr_fd.c 
# Liste des fichiers sources BONUS
# BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# 		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
# 		ft_lstmap.c
# Liste des fichiers Objets creer a partir de 'FILES' (Fichiers sources)
OBJ = $(FILES:.c=.o)
# Liste des fichiers Objets BONUS creer a partir de 'BONUS_FILES' (Fichiers sources)
# BONUS_OBJ = $(BONUS_FILES:.c=.o)

# Commande pour supprimer des fichiers avec option -f (pas d'erreur)
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$(NAME) created"
	ranlib $@
	@echo "$(NAME) indexed"

$(OBJ):		$(FILES)
	@gcc -c $(CFLAGS) $(FILES)

# bonus:		$(BONUS_FILES)
# 	@gcc -c $(FLAG) $(BONUS_FILES)
# 	@ar rcs $(NAME) $(BONUS_OBJ)
# 	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ) 
# $(BONUS_OBJ)
	@echo "OBJ deleted"

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re:	fclean all

.PHONY: all, clean, fclean, re