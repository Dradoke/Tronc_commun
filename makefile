# Liste des fichiers sources
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c
# Liste des fichiers sources BONUS
BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
# Liste des fichiers Objets creer a partir de 'FILES' (Fichiers sources)
OBJ = $(FILES:.c=.o)
# Liste des fichiers Objets BONUS creer a partir de 'BONUS_FILES' (Fichiers sources)
BONUS_OBJ = $(BONUS_FILES:.c=.o)
# Nom de la bibliotheque a generer
NAME = libft.a
# Options de compilations
CFLAGS = -Wall -Wextra -Werror
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

bonus:		$(BONUS_FILES)
	@gcc -c $(FLAG) $(BONUS_FILES)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)
clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "OBJ deleted"
fclean:		clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"
re:	fclean all
normi:		$(FILES)
	norminette $(FILES)
normib:	$(BONUS_FILES)
	norminette $(BONUS_FILES)
test:		 main.c $(NAME) bonus
	@gcc $(FLAG) main.c $(NAME) && ./a.out
git:
	git add .
	git commit -m "$m"
	git push origin main
.PHONY: all, clean, fclean, re