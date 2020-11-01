NAME = fdf

SOURCES = ./sources/main.c ./sources/read_input.c ./sources/initialize.c \
./sources/errors.c ./sources/free_all.c ./sources/draw.c ./sources/color.c \
./sources/projections.c ./sources/mouse_controls.c ./sources/key_controls.c

OBJECTS = $(subst .c,.o,$(SOURCES))

LIBFT = libft/libft.a

HEADERS = fdf.h

FLAGS = -Wall -Wextra #-Werror

LINKS = -L /usr/local/lib -lmlx -I /usr/local/X11/include \
	-L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

GREEN = \033[1;32m
RED = \033[1;31m
WHT = \033[1;37m
EOC = \033[1;0m

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

$(LIBFT):
	@echo "$(WHT)Compiling libft...$(EOC)"
	@make -C libft
	@echo "$(GREEN)Libft done.$(EOC)"

$(NAME): $(OBJECTS) $(LIBFT)
	@echo "$(WHT)Compiling FDF...$(EOC)"
	@gcc -o $(NAME) $(LINKS) $(OBJECTS) $(LIBFT)
	@echo "$(GREEN)Fdf build completed.$(EOC)"

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJECTS)
	@make -C libft clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re