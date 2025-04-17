NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = src/fdf.c src/get_next_line.c src/get_next_line_utils.c \
        src/parse_map.c src/parse_utils_1.c src/parse_utils_2.c \
        src/parse_utils_3.c src/init_map.c src/init_map_utils.c \
        src/draw_map.c src/draw_map_utils.c \

HEADER = src/fdf.h

OBJ = $(SRC:.c=.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean