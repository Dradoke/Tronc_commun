NAME = fdf

CFLAGS = -Wall -Wextra -Werror  #options de compilations

CC = gcc $(CFLAGS) #Compilateur

SOURCE_PATH = ./sources/

SOURCES_NAME = test.c

OBJECTS_PATH = ./objects/

OBJECTS_NAME = $(SOURCES_NAME:.c=.o)

SRC = $(addprefix $(SOURCE_PATH)/,$(SOURCES_NAME))

OBJ = $(addprefix $(OBJECTS_PATH)/,$(OBJECTS_NAME))

MLX_DIR = ./lib/minilibx

CPPFLAGS = -I ./lib/minilibx/ \ -I ./includes/

LFT = -lft

LDFLAGS = -L ./libft/

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		@make -C./libft/
		@echo "Creation of $(NAME)"
		@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
		@echo "$(NAME) created\n"

$(OBJECTS_PATH)%.o: $(SOURCE_PATH)%.c
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Removal of .o files of $(NAME) ..."
	@rm -f $(OBJ)
	@rmdir $(OBJECTS_PATH) 2> /dev/null || true
	@echo "Files .o deleted\n"

fclean: clean
	@make fclean -C ./libft/
	@echo "Removal of $(NAME)..."
	@rm -f $(NAME)
	@echo "Binary $(NAME) deleted\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re