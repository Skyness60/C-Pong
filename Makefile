NAME = pong

CC = cc -g3

SOURCES =	src/pong.c \
			src/check/check.c \
			src/hooks/hooks.c \
			src/map/draw.c


MLX_PATH = ./mlx/

MINI_LIBX = MiniLibX

MLX_FLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm

OBJECTS = $(SOURCES:.c=.o)
D_FILES = $(SOURCES:.c=.d)

FLAGS = -Wall -Wextra -Werror -MMD -MP
OPTIONS = -c

#################################################################################

RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
PURPLE = '\033[0;35m'
NC = '\033[0m'

#################################################################################

%.o: %.c
	@$(CC) $(FLAGS) $(OPTIONS) $< -o $@
	@echo $(GREEN)✅ $< compiled! $(NC)

$(NAME): $(OBJECTS) 
	@echo "$(BLUE)Building $(MINI_LIBX)..."
	@make -C $(MLX_PATH) --no-print-directory
	@echo $(GREEN)✅ MiniLibX built successfully!$(NC)
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) -L$(MLX_PATH) $(MLX_FLAGS)
	@echo $(BLUE)✅ $@ built! $(NC)

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(D_FILES)
	@make clean -C ${MLX_PATH} --no-print-directory
	@echo $(YELLOW)🗑️ $(OBJECTS) deleted! $(NC)

fclean: clean
	@rm -f $(NAME) $(BONUS) $(D_FILES)
	@echo $(RED)🗑️ $(NAME) deleted! $(NC)

re: fclean all

sinclude $(D_FILES)

.PHONY: all clean fclean re